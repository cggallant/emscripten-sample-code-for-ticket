#original
#docker run --rm -v ${pwd}:/src emscripten/emsdk:3.1.32 emcc product.cpp -s SIDE_MODULE=2 -O1 -o product.wasm

# new (each section is now a main module. I'll need to set a name for this and each JS file will need to be included in the html)
docker run --rm -v ${pwd}:/src emscripten/emsdk:3.1.32 emcc product.cpp -s MAIN_MODULE=2 -s MODULARIZE=1 -s "EXPORTED_RUNTIME_METHODS=['ccall']" -s ERROR_ON_UNDEFINED_SYMBOLS=0 -o product.js