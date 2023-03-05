mergeInto(LibraryManager.library, {
  UpdateHostAboutError: function(errorMessagePointer) {
    console.log(Module.UTF8ToString(errorMessagePointer));
  }
});