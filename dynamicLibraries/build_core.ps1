# original
#docker run --rm -v ${pwd}:/src emscripten/emsdk:3.1.32 emcc core.cpp -s MAIN_MODULE=2 -s MODULARIZE=1 -s "EXPORTED_FUNCTIONS=['_strlen']" -s "EXPORTED_RUNTIME_METHODS=['ccall']" -o core.js

# new (core is now a side module)
docker run --rm -v ${pwd}:/src emscripten/emsdk:3.1.32 emcc core.cpp -s SIDE_MODULE=2 -O1 -o core.wasm