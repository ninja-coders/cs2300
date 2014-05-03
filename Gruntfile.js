var shell = require('shelljs');

var buildDir = 'build';
var siteDir = 'site';

module.exports = function(grunt) {
  
  grunt.initConfig({
    pkg: grunt.file.readJSON('package.json'),
    jade: {
      compile: {
        options: {
          pretty: true
        },
        files: [{
          expand: true, 
          cwd: 'src/jade',
          src: '*.jade',
          dest: buildDir,
          ext: '.html'
        }]
      }
    },
    less: {
      build: {
        options: {
          paths: [buildDir + '/css']
        },
        files: {
          'build/css/site.css': 'src/less/site.less'
        }
      }
    },
    copy: {
      build: {
        files: [{
          expand: true, 
          src: ['lib/**'],
          dest: buildDir
        }]
      },
      publish: {
      }
    },
    clean: [buildDir + '/**/*']
  });

  grunt.loadNpmTasks('assemble');
  grunt.loadNpmTasks('grunt-newer');
  grunt.loadNpmTasks('grunt-contrib-jade');
  grunt.loadNpmTasks('grunt-contrib-less');
  grunt.loadNpmTasks('grunt-contrib-clean');
  grunt.loadNpmTasks('grunt-contrib-copy');

  grunt.registerTask('sayHello', 'Say Hi!', function() {
    grunt.log.write('Hello!!!').ok();
  });

  grunt.registerTask('setupRepo', 'Create the gh-pages directory for current project', function() {
    grunt.log.write('TODO: mkw').ok();
  });

  grunt.registerTask('pushChanges', 'Push site changes to github', function() {
    grunt.log.write('Pushing to gh-pages').ok();
  });

  grunt.registerTask('startServer', 'Start a static server', function() {
    var original =  process.cwd();
    process.chdir(buildDir);
    try {
      shell.exec('static-server');
    } catch (err) {
      grunt.log.write('Server stopped').ok();
    }
    process.chdir(original);
  });

  grunt.registerTask('build', ['clean', 'jade:compile', 'copy:build']);
  grunt.registerTask('preview', ['build', 'startServer']);
  grunt.registerTask('publish', ['build', 'setupRepo', 'newer:assemble', 'pushChanges']);
  grunt.registerTask('default', ['build']);
};

