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
    assemble: {
      options: {
        assets: 'dist'
      },
      index: {
        files: { 'site/index.html': [buildDir + '/index.html']},
        options: { 
          assets: 'dist',
          layout: 'none'
        }
      }
    }, 
    clean: [buildDir + '/*', siteDir + '/**/*.html']
  });

  grunt.loadNpmTasks('assemble');
  grunt.loadNpmTasks('grunt-newer');
  grunt.loadNpmTasks('grunt-contrib-jade');
  grunt.loadNpmTasks('grunt-contrib-clean');
  grunt.registerTask('build', ['clean', 'jade:compile', 'newer:assemble']);
  grunt.registerTask('default', ['build']);

  grunt.registerTask('sayHello', 'Say Hi!', function() {
    grunt.log.write('Hello!!!').ok();
  });

  grunt.registerTask('startServer', 'Start a static server', function() {
    var original =  process.cwd();
    process.chdir(siteDir);
    try {
      shell.exec('static-server');
    } catch (err) {
      grunt.log.write('Server stopped').ok();
    }
    process.chdir(original);
  });

  grunt.registerTask('preview', ['newer:assemble', 'startServer']);
};

