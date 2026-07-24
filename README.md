# ++Editor 3.6.2 source archive

The complete Qt Creator project is stored in `plusplus-editor-3.6.2.tar.gz`.
Keeping the real source and Debian packaging inside one tracked tar archive
prevents GitHub-generated ZIP downloads from changing project line endings,
permissions, or timestamps.

<b> Notice. Timestamps are in the past inside the archive. This is due to my dev system clock skew that happened during the development </b>
## Verify and extract

```bash
make verify
make extract
cd plusplus-editor-3.6.2
```

## Build and validate

```bash
make
make check
make valgrind
```

The inner project contains `Editor.pro`, native Qt tests, themes,
README screenshots, the build Makefile, Valgrind/ASan support, and complete
Debian packaging. Version 3.6.2 also hardens Qt 6.8 theme parsing and headless
test shutdown for cleaner Memcheck results.



# ++Editor 3.6.2

++Editor is a small traditional text editor written in C++ with Qt 6. It keeps
its design straightforward: `MainWindow` manages the window and tabs, `Form`
manages one document, and `Themes` applies the LWM themes.

**Author:** JJ Posti — [techtimejourney.net](https://www.techtimejourney.net)  
**License:** GPL-2.0-or-later OR Apache-2.0  
**Command:** `editor++`

## Features

- Movable, closable tabs and double-click tab creation
- UTF-8 text files, drag and drop, atomic saving, search, and printing
- Line numbers, current-line highlighting, word wrap, and zoom
- Font, size, bold, italic, underline, and text colour controls
- LWM Graphite, LWM Dark, and LWM Blue themes
- Bounded files, pastes, documents, and tab count

## LWM themes

Choose a theme from **View → Theme** or with `--theme`. The selection is saved
immediately and restored when ++Editor starts again. Select an image to view it
at full resolution.

### LWM Graphite

[![++Editor using the LWM Graphite theme](screenshots/graphite_theme)](screenshots/graphite_theme)

### LWM Dark

[![++Editor using the LWM Dark theme](screenshots/dark_theme)](screenshots/dark_theme)

### LWM Blue

[![++Editor using the LWM Blue theme](screenshots/blue_theme)](screenshots/blue_theme)

## Open files

```bash
editor++ notes.txt
editor++ first.txt second.md
editor++ --theme lwm-dark notes.txt
editor++ --help
```

The first file reuses the initial blank tab. Additional files open in new tabs.
A valid theme supplied with `--theme` is also saved for the next start.

## Build

Open `Editor.pro` in Qt Creator with a Qt 6 desktop kit, or run:

```bash
make
```

### Debian 13

```bash
sudo apt update
sudo apt install build-essential qmake6 \
  qt6-base-dev qt6-base-dev-tools qt6-qpa-plugins qt6-svg-plugins \
  desktop-file-utils appstream debhelper dpkg-dev devscripts valgrind
```

### Arch Linux

```bash
sudo pacman -S --needed base-devel qt6-base qt6-svg \
  desktop-file-utils appstream valgrind
```

### Fedora

```bash
sudo dnf install gcc-c++ make qt6-qtbase-devel qt6-qtsvg-devel \
  desktop-file-utils appstream valgrind
```

Valgrind is needed only for `make valgrind`. Debian packaging tools are needed
only for `make deb`.

## Checks and packaging

```bash
make tests          # native Qt tests
make check          # tests, CLI, desktop entry, and AppStream metadata
make sanitize       # AddressSanitizer and UndefinedBehaviorSanitizer
make valgrind       # bounded, quiet Memcheck run with debug symbols
make deb            # Debian binary package
sudo make install   # install to /usr PREFIX; DESTDIR is supported
sudo make uninstall # remove files installed by make install
make dist           # reproducible source archive
make clean
```

`make check` rejects source files dated in the future before starting qmake.
`make dist` writes a fixed past timestamp into every archive member, preventing
qmake regeneration loops after extraction.

The tests cover file arguments, UTF-8 I/O, line numbers, startup sizing, tab
destruction, theme loading, and theme persistence across a window restart.
Each run is time-bounded, so a regression cannot leave `make check` waiting on
a hidden modal dialog. The test-only logger removes only the headless QPA
plugin's known size-hint warning; every other application and Qt warning remains
visible. Valgrind uses the Debug test binary, quiet Qt Test output, and its own
crash diagnostics for readable Memcheck reports. It fails on definite, indirect,
or possible leaks. The native test executable selects the offscreen platform,
Fusion style, and `QT_NO_GLIB=1` before constructing `QApplication`; this keeps
direct Qt Creator runs deterministic and avoids GLib's process-wide event
dispatcher and retained `eventfd`. Theme selectors use Qt class and `objectName`
properties so Qt 6.8 does not enter the QCss type/ID index path that Memcheck
reports as an invalid read.

`tests/tests.pro` builds a separate `plusplus-editor-tests` executable from
`tst_editor.cpp`, `mainwindow.cpp`, `form.cpp`, and `themes.cpp`. It deliberately
does not compile `main.cpp`, and the test binary is not installed.

## Valgrind results on Debian

```bash
Testing EditorTests
Totals: 16 passed, 0 failed, 0 skipped, 0 blacklisted, 15440ms
```

## About file sizes

Files are limited to 8 MiB, documents to 8 Mi characters, one paste to 1 Mi
characters, and the window to 12 open tabs. Closed tabs use Qt parent ownership
and deferred deletion. Plain-text saves use `QSaveFile` and 64 Ki-character
chunks.
