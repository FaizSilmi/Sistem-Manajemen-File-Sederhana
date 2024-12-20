/*
	Nama		  : Muhammad Faiz Silmi (24343099)
	Project		  : Sistem Manajemen File Sederhana
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void createFile() {			// Fungsi untuk membuat file baru
    char filename[100];
    printf("Masukkan nama file yang ingin dibuat: ");
    getchar();				// Membersihkan buffer
    fgets(filename, sizeof(filename), stdin);   
    filename[strcspn(filename, "\n")] = '\0'; // strcspn menghapus karakter newline

    FILE *file = fopen(filename, "w");	// Membuka atau membuat file baru

    if (file == NULL) {
        printf("Gagal membuat file.\n");
    } else {
        printf("File \"%s\" berhasil dibuat.\n", filename);
        fclose(file);
    }
}

void writeFile() {			// Fungsi untuk menulis data ke file
    char filename[100];
    char content[500];
    
    printf("Masukkan nama file yang ingin ditulis: ");
    getchar();				// Membersihkan buffer
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = '\0'; // Menghapus karakter newline

    FILE *file = fopen(filename, "a");

    if (file == NULL) {
        printf("File tidak ditemukan.\n");
    } else {
        printf("Masukkan isi file: ");
        fgets(content, sizeof(content), stdin);

        fprintf(file, "%s", content);
        printf("Berhasil menulis ke file \"%s\".\n", filename);
        fclose(file);
    }
}

void readFile() {			// Fungsi untuk membaca dan menampilkan isi file
    char filename[100];
    char ch;

    printf("Masukkan nama file yang ingin dibaca: ");
    getchar();				// Membersihkan buffer
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = '\0'; // Menghapus karakter newline

    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("File tidak ditemukan.\n");
    } else {
        printf("Isi file \"%s\":\n", filename);
        while ((ch = fgetc(file)) != EOF) {
            putchar(ch);
        }
        fclose(file);
    }
}

void deleteFile() {			// Fungsi untuk menghapus file
    char filename[100];
    printf("Masukkan nama file yang ingin dihapus: ");
    getchar();				// Membersihkan buffer
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = '\0'; // Menghapus karakter newline

    if (remove(filename) == 0) {
        printf("File \"%s\" berhasil dihapus.\n", filename);
    } else {
        printf("Gagal menghapus file \"%s\".\n", filename);
    }
}

int main() {				// Fungsi utama program
    int choice;
    while (1) {
        printf("======Sistem Manajemen File Sederhana=======\n");
        printf("Nama	: Muhammad Faiz Silmi\n");
        printf("NIM	: 24343099\n");
        printf("============================================\n");
        printf("1. Buat file\n");
        printf("2. Tulis ke file\n");
        printf("3. Baca file\n");
        printf("4. Hapus file\n");
        printf("5. Keluar\n");
        printf("Pilih opsi (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createFile();
                break;
            case 2:
                writeFile();
                break;
            case 3:
                readFile();
                break;
            case 4:
                deleteFile();
                break;
            case 5:
                printf("Keluar dari program.\n");
                exit(0);
            default:
                printf("Opsi tidak valid, coba lagi.\n");
        }
    }

    return 0;
}
