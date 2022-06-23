        return Module;
    });

  return uzumeInitJsPromise;
}

if (typeof exports === 'object' && typeof module === 'object'){
    module.exports = factory;
    module.exports.default = factory;
}
else if (typeof define === 'function' && define['amd']) {
    define([], function() { return factory; });
}
else if (typeof exports === 'object'){
    exports["Module"] = factory;
}
