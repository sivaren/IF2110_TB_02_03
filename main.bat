@echo off
ECHO Compiling...

gcc main.c Buy/buy.c Buy/ListGadget.c daftarPesanan/daftarpesanan.c DROP_OFF/DROP_OFF.c help/help.c inProg/inProg_rev.c Inventory/Inventory.c Inventory/ListInventory.c Map/Listpoint.c Map/matrix.c Map/point.c  Map/map.c mesinKarKat/wordmachine.c mesinKarKat/charmachine.c Move/move.c pcolor/pcolor.c PICK_UP/PICK_UP.c tas/tas.c toDo/toDo.c END_GAME/END_GAME.c -o mainOutput

ECHO ~~~~~~~~~~~~~~~~~~~~~~~
ECHO Compilation successful!
ECHO.
