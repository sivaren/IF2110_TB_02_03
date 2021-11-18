# Tugas Besar IF2110 Algoritma dan Struktur Data (MOBILITA)
> _Program Ini Dibuat Untuk Memenuhi Tugas Perkuliahan Mata Kuliah Algoritma dan Struktur Data (IF2110)_ <br/>
>
> _Program Studi Teknik Informatika <br/>
> Sekolah Teknik Elektro dan Informatika <br/>
> Institut Teknologi Bandung <br/>
> Semester I Tahun 2021/2022 <br/>_

## Daftar Isi
* [Deskripsi Program](#deskripsi-program)
* [Prasyarat](#prasyarat)
* [Run Program](#run-program)
* [Fitur Program](#fitur-program)
* [Status Pengerjaan](#status-pengerjaan)
* [Pembagian Tugas](#pembagian-tugas)

## Deskripsi Program
- Sebuah permainan berbasis **CLI** (_command-line interface_) tentang pengantaran barang
- Permainan dibuat dalam **bahasa C** dengan menggunakan struktur data yang telah dipelajari di mata kuliah (IF2110)

## Prasyarat
> **Pastikan branch repository berada di `main`** </br>

**Clone repository ini menggunakan command berikut (git bash)**
```
$ git clone https://github.com/sivaren/IF2110_TB_02_03.git
```

## Run Program
> **To first setup this project run** </br>

**Windows (Open `PowerShell` on this folder)**
```
    cd src
    ./main.bat
```
> **Akan terdapat file `mainOutput.exe` pada current directory, program siap dijalankan**  </br>

**Run program dengan command sebagai berikut**
```
    ./mainOutput
```

## Fitur Program
<table>
    <tr>
      <td><b>Fitur</b></td>
      <td><b>Deskripsi</b></td>
    </tr>
    <tr>
      <td><b>START_GAME</b></td>
      <td><b>Untuk memulai permainan baru</b></td>
    </tr>
    <tr>
      <td><b>LOAD_GAME</b></td>
      <td><b>Untuk memulai permainan dengan game state yang telah ada</b></td>
    </tr>
    <tr>
      <td><b>EXIT</b></td>
      <td><b>Keluar dari permainan</b></td>
    </tr>
    <tr>
      <td><b>MOVE</b></td>
      <td><b>Untuk berpindah ke lokasi selanjutnya</b></td>
    </tr>
    <tr>
      <td><b>PICK_UP</b></td>
      <td><b>Untuk mengambil item di lokasi terkini</b></td>
    </tr>
    <tr>
      <td><b>DROP_OFF</b></td>
      <td><b>Untuk mengantarkan item ke lokasi terkini</b></td>
    </tr>
    <tr>
      <td><b>MAP</b></td>
      <td><b>Untuk menampilkan peta permainan</b></td>
    </tr>
    <tr>
      <td><b>TO_DO</b></td>
      <td><b>Untuk menampilkan pesanan yang masuk ke To Do List</b></td>
    </tr>
    <tr>
      <td><b>IN_PROGRESS</b></td>
      <td><b>Untuk menampilkan pesanan yang sedang dikerjakan</b></td>
    </tr>
    <tr>
      <td><b>BUY</b></td>
      <td><b>Untuk menampilkan gadget yang dapat dibeli lalu membelinya</b></td>
    </tr>
    <tr>
      <td><b>INVENTORY</b></td>
      <td><b>Untuk melihat gadget yang dimiliki dan menggunakannya</b></td>
    </tr>
    <tr>
      <td><b>SAVE_GAME</b></td>
      <td><b>Untuk menyimpan state dari permainan yang sedang dijalankan</b></td>
    </tr>
    <tr>
      <td><b>HELP</b></td>
      <td><b>Untuk mengeluarkan list command dan kegunaannya
</b></td>
    </tr>
</table>

## Status Pengerjaan
> **Project is: _complete_**

## Pembagian Tugas
<table>
    <tr>
      <td><b>Nama</b></td>
      <td><b>NIM</b></td>
      <td><b>Tugas</b></td>
    </tr>
    <tr>
      <td><a href="https://github.com/SurTan02"><b>Suryanto</b></a></td>
      <td><b>13520059</b></td>
      <td>
        <ul>
            <p></p>
            <li> Baca File Konfigurasi </li>
            <li> Daftar Pesanan </li>
            <li> Save dan Load </li>
        </ul>
      </td>
    </tr>
    <tr>
      <td><a href="https://github.com/ziyaddr"><b>Ziyad Dhia Rafi</b></a></td>
      <td><b>13520064</b></td>
      <td>
        <ul>
            <p></p>
            <li> Pick Up </li>
            <li> Drop Off </li>
        </ul>
      </td>
    </tr>
    <tr>
      <td><a href="https://github.com/OjaanIr"><b>Farnas Rozaan Iraqee</b></a></td>
      <td><b>13520067</b></td>
      <td>
        <ul>
            <p></p>
            <li> Move </li>
            <li> Map </li>
        </ul>
      </td>
    </tr>
    <tr>
      <td><a href="https://github.com/lyorafelicya"><b>Lyora Felicya</b></a></td>
      <td><b>13520073</b></td>
      <td>
        <ul>
            <p></p>
            <li> Buy </li>
            <li> Inventory </li>
        </ul>
      </td>
    </tr>
    <tr>
      <td><a href="https://github.com/sivaren"><b>Rava Naufal Attar</b></a></td>
      <td><b>13520077</b></td>
      <td>
        <ul>
            <p></p>
            <li> To Do List </li>
            <li> In Progress List </li>
            <li> Help </li>
        </ul>
      </td>
    </tr>
</table>
