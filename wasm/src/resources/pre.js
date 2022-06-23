var uzumeInitJsPromise = undefined;

var factory = function (moduleConfig) {

    if (uzumeInitJsPromise){
      return uzumeInitJsPromise;
    }
    uzumeInitJsPromise = new Promise(function (resolveModule, reject) {
        var Module = typeof moduleConfig !== 'undefined' ? moduleConfig : {};
        var originalOnAbortFunction = Module['onAbort'];
        Module['onAbort'] = function (errorThatCausedAbort) {
            reject(new Error(errorThatCausedAbort));
            if (originalOnAbortFunction){
              originalOnAbortFunction(errorThatCausedAbort);
            }
        };

        Module['postRun'] = Module['postRun'] || [];
        Module['postRun'].push(function () {
            resolveModule(Module);
        });

        module = undefined;
