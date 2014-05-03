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
};

