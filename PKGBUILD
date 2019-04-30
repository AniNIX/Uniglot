# Maintainer: Shikoba Kage <darkfeather@aninix.net>
pkgname=uniglot
pkgver=0.1.e7c96f9
pkgver() {
    printf "0.1.""$(git rev-parse --short HEAD)"
}
pkgrel=1
epoch=
pkgdesc="AniNIX::Uniglot \\\\ Shared code libraries that all the AniNIX projects should use -- this should reduce error and code duplication"
arch=("x86_64")
url="https://aninix.net/foundation/Uniglot"
license=('custom')
groups=()
depends=('mono>=5.0.0' 'curl' 'grep' 'bash>=4.4' 'git>=2.13')
makedepends=('make>=4.2')
checkdepends=()
optdepends=()
provides=('uniglot')
conflicts=()
replaces=()
backup=()
options=()
install=
changelog=
source=()
noextract=()
md5sums=()
validpgpkeys=()

prepare() {
    git pull
}

build() {
    make -C ..
}

check() {
	printf 'quit\n\n' | make -C "${srcdir}/.." test
}

package() {
    export pkgdir="${pkgdir}"
	make -C .. install
    install -D -m644 ../LICENSE "${pkgdir}/usr/share/licenses/${pkgname}/LICENSE"
}
