def ragel(*args)
  sh "ragel", "-I.", *args
end

# Build state machine before building gem.
task :build => :compile

file "parser_common.rl"

rule ".rb" => %w[.rb.rl parser_common.rl] do |t|
  ragel "-F1", "-R", t.source, "-o", t.name
end

rule ".c" => %w[.c.rl parser_common.rl] do |t|
  ragel "-G2", "-C", t.source, "-o", t.name
end

rule ".java" => %w[.java.rl parser_common.rl] do |t|
  ragel "-T0", "-J", t.source, "-o", t.name
end

desc "ragel machines"
task :compile => %w[lib/stomp_parser/ruby_parser.rb]

# JRuby do not like C extensions to even exist.
if %w[rbx ruby].include?(RUBY_ENGINE)
  require "rake/extensiontask"
  task :compile => %w[ext/stomp_parser/c_parser.c]

  Rake::ExtensionTask.new do |ext|
    ext.name = "c_parser"
    ext.ext_dir = "ext/stomp_parser"
    ext.lib_dir = "lib/stomp_parser"
  end
end

require "rake/javaextensiontask"
task :compile => %w[ext/java/stomp_parser/JavaParser.java]

Rake::JavaExtensionTask.new do |ext|
  ext.name = "java_parser"
  ext.lib_dir = "lib/stomp_parser"
end

desc "ragel machines"
task :clean do |t|
  source_tasks = Rake::Task[:compile].prerequisite_tasks.grep(Rake::FileTask)
  rm_f source_tasks.map(&:name)
end

namespace :ragel do
  desc "Show stomp parser state machine as an image"
  task :show => "lib/stomp_parser/ruby_parser.rb" do |t|
    mkdir_p "tmp"
    ragel "-V", "-p", t.prerequisite_tasks[0].source, "-o", "tmp/parser.dot"
    sh "dot -Tpng -O tmp/parser.dot"
    rm "tmp/parser.dot"
    sh "open tmp/parser.dot.png"
  end
end

desc "Start a pry session with the gem loaded."
task :console => :compile do
  exec "pry", "-rbundler/setup", "-rstomp_parser"
end

require "rspec/core/rake_task"
RSpec::Core::RakeTask.new(:spec)
task :spec => :compile

desc "Run all benchmarks."
task :bench => :compile do
  sh "ruby", "-I.", *FileList["spec/benchmarks/**/*.rb"].flat_map { |x| ["-r", x] }, "-e", "''"
end

desc "Run the profiler and show a gif, requires perftools.rb"
task :profile => :compile do
  # CPUPROFILE_METHODS=0 CPUPROFILE_OBJECTS=0 CPUPROFILE_REALTIME=1
  sh "CPUPROFILE_REALTIME=1 ruby spec/profile.rb"
  sh "pprof.rb --text spec/profile/parser.profile"
end

desc "Build gem in preparation for release"
task :build, [:everything_compiled?] => :compile do |task, args|
  unless args[:everything_compiled?] == "all_compiled"
    puts "Hi there. This is a safeguard to stop you from doing mistakes."
    puts
    puts "Make sure that the lib/stomp_parser/java_parser.jar is up to"
    puts "date by switching to JRuby and running `rake compile`. This is"
    puts "because JRuby cannot build native extensions on gem installation,"
    puts "so we must bundle the .jar with the gem."
    puts
    puts "To do this, switch to JRuby and issue `rake compile`."
    puts
    puts "Once you've compiled the parser, run `rake build[all_compiled]`"
    puts "to build gems for all platforms!"
    abort
  end

  require "rubygems/package"

  root = File.dirname(__FILE__)
  pkgs = File.join(root, "pkg/")
  mkdir_p(pkgs, verbose: true)

  gemspec = Gem::Specification.load("stomp_parser.gemspec")

  # For all the rubies. Except JRuby.
  ruby_gemspec = gemspec.dup
  ruby_gemspec.platform = Gem::Platform::RUBY
  ruby_gemname = Gem::Package.build(ruby_gemspec)
  ruby_gempath = File.join(pkgs, File.basename(ruby_gemname))
  mv(ruby_gemname, ruby_gempath, verbose: true)

  # JRuby don't like C extensions.
  java_gemspec = gemspec.dup
  java_gemspec.files += ["lib/stomp_parser/java_parser.jar"]
  java_gemspec.extensions = []
  java_gemspec.platform = "universal-java"
  java_gemname = Gem::Package.build(java_gemspec)
  java_gempath = File.join(pkgs, File.basename(java_gemname))
  mv(java_gemname, java_gempath, verbose: true)

  puts
  puts "Now you may push the gems:"
  puts
  puts "  gem push #{ruby_gempath}"
  puts "  gem push #{java_gempath}"
  puts
  puts "Do not forget to tag and push the versions to GitHub!"
end


task :default => :spec
