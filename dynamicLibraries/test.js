const MAXIMUM_NAME_LENGTH = 10;

let productModule = null;

function init(){
    Module({ dynamicLibraries: ['product.wasm'] }).then((module) => {
        productModule = module;
    });
}

function validate(){
    // ValidateName in product.wasm will call the ValidateValueProvided function that's in the core.wasm 
    // which will in turn call the UpdateHostAboutError JS function (does a console.log in this case).
    productModule.ccall('ValidateName',
        'number',
        ['string', 'number'],
        ["this value would usually come from an input control", MAXIMUM_NAME_LENGTH]);
}