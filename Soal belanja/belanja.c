#include <stdio.h>

int main() {
	// membaut variable yang dibutuhkan, menggunakan double agar bisa menampung nilai desimal
    double belanja, totalBelanja , bayar , diskonPembelian , diskonTransaksi , totalBayar, totalDiskonPembelian;
    /* char digunakan untuk user memasukkan 1 huruf saja yaitu diantara : y, Y, n, N
    y,Y = yes
    n, N = no*/
    char pertanyaan;
    // variable percobaan untuk looping agar tidak infinite
    int percobaan = 1, maxPercobaan = 10;
    
	// melakukan looping dengan for loop
    for (percobaan = 1; percobaan <= maxPercobaan; percobaan++) {
        printf("\nApakah Anda ingin melanjutkan transaksi? (y / n): ");
        scanf(" %c", &pertanyaan);
		// meminta user memasukkan input char, 1 huruf saja dari (y, Y, n, N)
        if (pertanyaan == 'y' || pertanyaan == 'Y') {
             printf("\n\x1b[32m=========================================\n"); // \x1b[32 muntuk membuat text berwarna hijau
            printf("      Selamat Datang Di Toko Dzaki       ");
            printf("\n=========================================\x1b[0m\n");

            // meminta user memasukkan harga belanja
            printf("\nMasukkan Total Belanja Pembeli: RP ");
            scanf("%lf", &belanja);

             /*UNTUK NILAI 500.001 - 549.999, SAYA MASUKKAN DALAM CABANG KE 3 YAITU DISKON 20% */
            if (belanja > 0 && belanja < 200000)
            {
                diskonPembelian = belanja * 0 ;             // membuat diskon pemebelian
                bayar = belanja * 1;               // membuat bayar
            }
            else if (belanja >= 200000 && belanja <= 500000)
            {
                diskonPembelian = belanja * 0.1;           // membuat diskon pemebelian
                bayar = belanja * 0.9  ;                  // membuat bayar
            }
            else if (belanja > 500000 && belanja <= 1000000)
            {
                diskonPembelian = belanja * 0.2;         // membuat diskon pemebelian
                bayar = belanja * 0.8 ;                 // membuat bayar
            }
            else if (belanja > 1000000)
            {
                diskonPembelian = belanja * 0.3 ;      // membuat diskon pemebelian
                bayar = belanja * 0.7 ;               // membuat bayar
            }
            else
            {
                printf("\033[31mInput Invalid!!! (masukkan input angka > 0)\x1b[0m \n");
                return 1; //keluar program jika invalid
            }
            
            
            //total diskonPembelian
				totalDiskonPembelian += diskonPembelian;
                // Menghitung total belanja
                totalBelanja += belanja;

                // Logika untuk menghitung diskon transaksi
                if (percobaan > 3) {
                    diskonTransaksi = (totalBelanja - totalDiskonPembelian)  * 0.2;
                    printf("\n==========================================\n");
        			printf("\x1b[34;47mSelamat Kamu Mendapatkan Diskon Transaksi :) \x1b[0m"); // \x1b[34;47m untuk membuat text berwarna biru dan bg-text putih
                }

				// Menghitung total bayar
                totalBayar = totalBelanja - diskonTransaksi - totalDiskonPembelian; 

			// Keluar dari loop setelah transaksi selesai menggunakan pertanyaan sebelumnya
			}else if (pertanyaan == 'n' || pertanyaan == 'N') {
			
			// output yang diterima user setelah menggunakan program	
           printf("\n\x1b[33m=========== Detail Transaksi ===========\x1b[0m\n");                                // \x1b[33m untuk membuat text berwarna kuning
            printf("Total Belanja Keseluruhan   : RP %.2lf\n", totalBelanja);                                   // total belanja
            printf("Diskon Pembelian            : RP %.2lf\n", totalDiskonPembelian);                          // Total diskon pembelian
            printf("Diskon Transaksi            : RP %.2lf\n", diskonTransaksi);                              // Diskon transaksi
            printf("Total Diskon (Anda Hemat!!!): RP %.2lf\n", totalDiskonPembelian + diskonTransaksi);      // Total diskon yang di dapat user
            printf("Total yang harus dibayar    : RP %.2lf\n", totalBayar);                             	// harga yang perlu di bayar user
            printf("\n=====================================\n");
            printf("            Terima Kasih  ");
            printf("\n=====================================\n");
            return 1;
        } else {
            printf("\033[31m Input Invalid!!! (masukkan 'y' atau 'n') \x1b[0m\n");
            return 1; // keluar program jika invalid
        }
    }
        return 0;
		}


