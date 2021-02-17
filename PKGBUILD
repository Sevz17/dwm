# Maintainer: Leonardo Hernández <leohdz172@outlook.com>
pkgname=dwm
pkgver=6.2
pkgrel=1
pkgdesc="A dynamic window manager for X - patched version"
arch=('x86_64')
url="https://github.com/Sevz17/dwm.git"
license=('MIT')
depends=('libmpdclient' 'libxinerama' 'libxft' 'libx11')
optdepends=('st' 'dmenu' 'slstatus')
source=("$pkgname-$pkgver.tar.gz")
sha256sums=('SKIP')

build() {
  cd "$srcdir/$pkgname"
  make
}

package() {
  cd "$srcdir/$pkgname"
  make PREFIX=/usr DESTDIR="$pkgdir" install
  install -m644 -D LICENSE "$pkgdir/usr/share/licenses/$pkgname/LICENSE"
  install -m644 -D README "$pkgdir/usr/share/doc/$pkgname/README"
  install -m644 -D applied_patches.txt "$pkgdir/usr/share/doc/$pkgname/applied_patches.txt"
  install -m644 -D "$srcdir/$pkgname/dwm.desktop" "$pkgdir/usr/share/xsessions/dwm.desktop"
}
