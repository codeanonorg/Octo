.PHONY: build clean

build:
	@ echo "[building octo]"
	@ mkdir -p build
	@ cd build ; cmake ../src ; make
	@ echo "[done]"

clean:
	rm -rf build



