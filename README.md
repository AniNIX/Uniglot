This repo holds all our standard functions that all our services should use. We include a folder for each language -- files are broken down by their inclusion method. Please follow our [development best practices](https://foundation.aninix.net/AniNIX/Wiki/src/branch/master/Operation/Development_Best_Practices.md) when contributing.

Some other functions served by this repo are included below.

# Example Packaging

This repo does have some example packaging for use in downstream projects. The `Makefile` and `PKGBUILD` are standards the AniNIX should maintain throughout their projects.

# Executables

The following executables are available:

* `uniglot-clone` ensures that when repos are cloned, they are attached to the standard Uniglot hooks.
* `home-git` is support for [User Support Repositories](https://aninix.net/AniNIX/Wiki/src/branch/main/Articles/User_Support_Repositories.md).
