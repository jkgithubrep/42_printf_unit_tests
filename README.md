# Printf unit test

Collection of unit tests for the project *ft_printf* at [42](https://www.42.fr/).
All the tests are stored in a single *tests.txt* file and automatically created by a script, so you can add your own tests to the existing ones.


## Getting started

```
git clone https://github.com/jkgithubrep/42_printf_unit_tests.git
```

## Usage
### Content

The repository contains three main folders:
- **framework**: contains all the files necessary to create the *libunit.a* library used to load and launch the different tests;
- **templates**: contains the different templated files used to automatically generate the tests;
- **tests**: contains all the tests seperated in different folders (ex: *conv_d* for the `%d` conversion specifier, *conv_f* for the `%f` conversion specifier, etc...), the *generator.sh* script to automate the test creation, the *tests.txt* file which contains all the tests and the *Makefile* to compile the tests.
```
.
├── README.md
├── framework
├── templates
└── tests
```

### Basic usage
1) `cd tests`
2) Change the path to your ft_printf project at the top of the Makefile 
![Makefile](images/makefile_libftprintf_path.png)
3) `make test`

### Advanced usage


## Author

by **jkettani**

## License

This project is licensed under the **GNU General Public License v3.0**.
