var shell = require('shelljs');

module.exports = function(grunt) {
  
  grunt.initConfig({
    pkg: grunt.file.readJSON('package.json')
  });

  grunt.loadNpmTasks('assemble');
  grunt.loadNpmTasks('grunt-newer');
  grunt.registerTask('default', ['newer:assemble']);

  grunt.registerTask('sayHello', 'Say Hi!', function() {
    grunt.log.write('Hello!!!').ok();
  });

  grunt.registerTask('startServer', 'Start a static server', function() {
    var original =  process.cwd();
    process.chdir('build');
    try {
      shell.exec('static-server');
    } catch (err) {
      grunt.log.write('Server stopped').ok();
    }
    process.chdir(original);
  });

  grunt.registerTask('preview', ['newer:assemble', 'startServer']);
};

