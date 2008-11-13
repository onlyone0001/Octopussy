=head1 NAME

Octopussy::Cache - Octopussy Cache module

=cut
package Octopussy::Cache;

use strict;

use Cache::FileCache;

use AAT;

use constant EXPIRES_DISPATCHER => "2 days";
use constant EXPIRES_EXTRACTOR => "1 hour";
use constant EXPIRES_PARSER => "1 day";
use constant EXPIRES_REPORTER => "1 day";
use constant DIRECTORY_UMASK => "007";

my ($cache_dispatcher, $cache_extractor, $cache_parser, $cache_reporter) 
  = (undef, undef, undef);

=head1 FUNCTIONS

=head2 Init($namespace)

=cut
sub Init($)
{
  my $namespace = shift;
  
  if ($namespace eq "octo_dispatcher")
  {
    if (AAT::NULL($cache_dispatcher))
      { $cache_dispatcher = Set($namespace, EXPIRES_DISPATCHER); }
    return ($cache_dispatcher);
  }
  elsif ($namespace eq "octo_extractor")
  {
    if (AAT::NULL($cache_extractor))
      { $cache_extractor = Set($namespace, EXPIRES_EXTRACTOR); }
    return ($cache_extractor);
  } 
  elsif ($namespace eq "octo_parser")
  {
    if (AAT::NULL($cache_parser))
      { $cache_parser = Set($namespace, EXPIRES_PARSER); }
    return ($cache_parser);
  }
  elsif ($namespace eq "octo_reporter")
  {
    if (AAT::NULL($cache_reporter))
      { $cache_reporter = Set($namespace, EXPIRES_REPORTER); }
    return ($cache_reporter);
  }
  
  return (undef);
}

=head2 Set($namespace, $expires)

=cut
sub Set($$)
{
  my ($namespace, $expires) = @_;

  my $cache = new Cache::FileCache( { namespace => $namespace,
    cache_root => Octopussy::Directory("running") . "/cache",
    default_expires_in => $expires, directory_umask => DIRECTORY_UMASK } )
    or croak( "Couldn't instantiate FileCache" );

  return ($cache);
}

1;

=head1 AUTHOR

Sebastien Thebert <octo.devel@gmail.com>

=cut