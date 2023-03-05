const MAXIMUM_NAME_LENGTH = 10;

let productModule = null;

function init(){
    Module({ dynamicLibraries: ['product.wasm'] }).then((module) => {
        productModule = module;
    });
}

function validate(){
    // ValidateName in product.wasm will call the ValidateValueProvided function that's in the core.wasm
    const result = productModule.ccall('ValidateName',
        'number',
        ['string', 'number'],
        ["this value would usually come from an input control", MAXIMUM_NAME_LENGTH]);

    console.log(`Issue? ${ (result === 0 ? "Yes" : "No") }`);
}