# rewindow
a simple Windows utility for moving/resizing windows

## How to
1. Run `rewindow --capture > myprofile.txt` to dump the state of all top-level windows.
2. Review the file.  Delete any lines describing windows you don't care about.
3. Whenever you wish to restore sizes/positions to that state, run `rewindow --apply myprofile.txt`.  Windows are matched by name.

## Technical
`rewindow` is built on Windows with `g++`.  Tested on Windows 11 64-bit.  No special libraries or dependencies.
