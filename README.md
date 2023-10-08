This repo holds all our standard functions that all our services should use. We include a folder for each language -- files are broken down by their inclusion method. Please follow our [development best practices](https://foundation.aninix.net/AniNIX/Wiki/src/branch/master/Operation/Development_Best_Practices.md) when contributing.

Some other functions served by this repo are included below.

# Etymology

`Uniglot` is derived from the idea of a universal language to be used by all projects. `Uni` means one, and glot [is defined](https://www.collinsdictionary.com/us/dictionary/english/glot#:~:text=%2Dglot%20in%20American%20English,polyglot) as '"speaking, writing, or written in a language" of the kind or number specified by the initial element'. So, Uniglot is thereby the single language used by all AniNIX projects. This refers both to the library files contained here and the universal hooks used in AniNIX development.

# Relevant Files and Software

## Example Packaging

This repo does have some example packaging for use in downstream projects. The [Makefile](./Makefile) and [PKGBUILD](./PKGBUILD) are standards the AniNIX should maintain throughout their projects.

## Executables

The following executables are available:

* `uniglot-clone` ensures that when repos are cloned, they are attached to the standard Uniglot hooks.
* `home-git` is support for [User Support Repositories](https://aninix.net/AniNIX/Wiki/src/branch/main/Articles/User_Support_Repositories.md).

## Hooks

The Hooks folder includes a standard pre-commit and pre-receive that will be enforced across repos. These pre-commit and pre-receive will enforce the contents of `Hooks/scripts.d`. This allows us to enforce standards of quality across the ecosystem.

Notably, each repo that subscribes to this enforcement can also commit their own standards in addition to global standards. Python tests should go in a folder called `tests/` and scripts in a folder called `precommit-hooks/`. These will be run in addition to the global hooks.

## Standard Libraries

Each language for which we have libraries should have its own folder. Breakdown within each of these may be broken up by line count or topic, at the author's discretion. Once an include standard has been set, though, it should be preserved. For example, if functions in [the Bash header](./Bash/header) are to be broken out into subordinate files, then the Bash header should include these files that contain functions formally in itself.

# Available Clients

The clients for this package are the compilers for the various languages represented.

* `bash` for Bash
* `mono` for C#
* `gcc` for C
* `javac` for Java

The hooks can be consumed by `git` when `uniglot-clone` is run on a repo.

# Equivalents or Competition

The equivalents for this are the -headers or -libs packages for other projects. There is not really competition, as these are things specific for our development environment.
