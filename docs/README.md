# About the documentation

## Building the documentation

To build the documentation, first install the necessary documentation python packages. These are available in `docs`
optional dependencies:

```console
$ pip install .[docs]
```

Then, to build the documentations simply run:

```console
$ sphinx-build . ./build
```

For more intensive documentation editing I recommend using `sphinx-autobuild` which serves the generated documentation
(default `http://127.0.0.1:8000`) and automatically rebuilds it whenever you make changes.

```console
$ sphinx-autobuild . ./build
```
