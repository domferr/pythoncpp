.PHONY: clean build

UNAME_S := $(shell uname -s)

# if we are on macos, we will need to set SDKROOT properly
ifeq ($(UNAME_S),Darwin)
  MACOS_SDKROOT := $(shell xcrun --sdk macosx --show-sdk-path)
endif

build: clean
ifeq ($(UNAME_S),Darwin)
	@echo "Building on macOS with SDKROOT=$(MACOS_SDKROOT)"
	SDKROOT=$(MACOS_SDKROOT) pip install .
else
	pip install .
endif

clean:
	@echo "Cleaning..."
	rm -rf build
	rm -rf *.egg-info
	pip uninstall datastruct -y