#!/usr/local/bin/perl -w

# This is a perl script for keeping the support code
# for the 15-410 kernel up to date.
#
# Zachary Anderson(zra)
#
###########################################################
# Usage:
#    update.pl <how>
#
#       <how>:
#              afs - update files by comparing md5sums
#                    taken from course afs space. If
#                    files don't match digests, grab
#                    updated files from course afs space.
#
#              web - same but from course webspace.
#
#              offline - build support libraries using
#                    code present in local directories.
#                    This method is *not* recommended for
#                    typical use.
#
#              afs_source - update source code for support
#                    libraries from course afs space
#
#              web_source - update source code for support
#                    libraries from course web space.
#
###########################################################

use strict;

# location of official support code and libraries
my $afs_path = "/afs/cs.cmu.edu/academic/class/15410-s04/Web/update/proj1";
my $web_url  = "http://www-2.cs.cmu.edu/~410/update/kern_libs";
my $work_dir = $ENV{"PWD"};

#
# reletive paths to look in for support libraries.
#
my @lib_paths = ( ".",
                  "lib" );

#
# reletive paths to look in for support code.
#
my @source_paths = ( "lib/inc",
                     "lib/lmm",
                     "lib/multiboot",
                     "lib/x86",
                     "lib/stdio",
                     "lib/stdlib",
                     "lib/string" );

#
# grab the command line argument
#
my $arg = $ARGV[0];


#
# Prototypes.
#
sub run;
sub updater;
sub afs_check_dir;
sub web_check_dir;
sub offline;

#
# Go!
#
run( $arg );

#
# Look at the command line argument and do the right thing.
#
sub run
{
    my $a = $_[0];

    if( $a =~ /^afs$/ ) {
        updater( \@lib_paths, $afs_path, \&afs_check_dir);
    }
    elsif( $a =~ /^web$/ ) {
        updater( \@lib_paths, $web_url, \&web_check_dir );
    }
    elsif( $a =~ /^offline$/ ) {
        offline();
    }
    elsif( $a =~ /^afs_source$/ ) {
        updater( \@source_paths, $afs_path, \&afs_check_dir );
    }
    elsif( $a =~ /^web_source$/ ) {
        updater( \@source_paths, $web_url, \&web_check_dir );
    }
    else {
        print "Invalid Argument\n";
    }
}

#
# Takes a reference to an array of reletive paths to update,
#       a string that supplies the full path be it an afs path or url,
#       and a reference to the function to call to update the directory.
#
sub updater
{
    my $array_ref = $_[0];
    my $locator = $_[1];
    my $func_ref = $_[2];
    my $p;

    foreach $p (@{$array_ref}) {
        &{$func_ref}( "$locator/$p" );
    }
}

#
# Uses md5sum to check the files in the local directory against the
# digests stored in the course afs space. If a file doesn't match,
# copy the file from the course afs space into the local directory.
#
sub afs_check_dir
{
    my $d = $_[0];

    my $file;
    my $afs_file_home;
    my $local_file_home;
    my $local_dir;
    my($pid, $status, $return);

    $local_file_home = substr( $d, length( $afs_path ) + 1 );
    $local_dir = "$work_dir/$local_file_home";

    foreach $file (glob( "$d/*.md5" )) {
        $pid = fork();
        if( $pid == 0 ) {
            chdir $local_file_home;
            exec "md5sum", ("-c", "$file");
        }
        elsif( $pid ) {
            wait;
            $status = $?;
        }
 
        if( $status ) {
            print "file not up to date. grabbing the new one.\n";
            $afs_file_home = substr( $file, 0, -4 );
            `cp $afs_file_home $local_file_home`;
        }
    }
}

#
# Downloads the digests from course webspace into the local directory.
# For each digest uses md5sum to check the files in the local directory.
# If the file doesn't match the digest, download the file from course
# web space into the local directory.
#
sub web_check_dir
{
    my $web_dir = $_[0];

    my($local_md5_dir, $local_md5_file);
    my($pid, $status);

    $web_dir =~ /^($web_url)\/(.*)/;
    $local_md5_dir = "$work_dir/$2";

    #
    # grab .md5 files from the url $web_dir
    #
    `wget -r -l 1 -np -A .md5 -nd -P $local_md5_dir -q $web_dir`;
    unlink "$local_md5_dir/index.html"; # grrr

    #
    # For each digest in $local_md5_dir...
    #
    foreach $local_md5_file (glob( "$local_md5_dir/*.md5" )) {
        my $f;

        #
        # glob gives $local_md5_file = $local_md5_dir/blah.md5... 
        # just want blah.md5 sometimes.
        #
        $local_md5_file =~ /^($local_md5_dir)\/(.*)/;
        $f = $2;

        $pid = fork();
        if( $pid == 0 ) {
            chdir $local_md5_dir;
            exec "md5sum", ("-c", "$f");
        }
        elsif( $pid ) {
            wait;
            $status = $?;
        }

        if( $status ) {
            my $local_file = substr( $f, 0, -4 );
            my $file_url = "$web_dir/$local_file";
            print "$local_file not up to date. grabbing the new one\n";
            `wget --cache=off --quiet -P $local_md5_dir $file_url`;
        }
        unlink "$local_md5_dir/$f";
    }
}

sub offline
{
    print "**************************************************************\n";
    print "This option is *not* recommended! Please be sure to \"make afs\"\n";
    print "or \"make web\" with some frequency\n";
    print "**************************************************************\n";
}
