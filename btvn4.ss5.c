#include <stdio.h>
#include <string.h>
#define MAX 100
#define TEN_MAX 30
#define PHI_GOC 200000
#define PHI_BHYT 40000


int so_thu_tu[MAX];
char ten_benh_nhan[MAX][TEN_MAX];
int tuoi[MAX];
int uu_tien[MAX];
int bao_hiem[MAX];
int mang_thai[MAX];
int phi_kham[MAX];

int bac_si[MAX];
int khung_gio[MAX];

int n = 0;

void xoa_enter(char str[]) {
    str[strcspn(str, "\n")] = '\0';
}


void cap_nhat_uu_tien(int i) {

    if (tuoi[i] > 70 || mang_thai[i] == 1) {
        uu_tien[i] = 1;
    } else {
        uu_tien[i] = 0;
    }
}
void cap_nhat_phi(int i) {

    if (bao_hiem[i] == 1) {
        phi_kham[i] = PHI_BHYT;
    } else {
        phi_kham[i] = PHI_GOC;
    }
}

int kiem_tra_tai_bac_si(int bs, int gio) {

    int i;
    int dem = 0;

    for (i = 0; i < n; i++) {

        if (bac_si[i] == bs && khung_gio[i] == gio) {
            dem++;
        }
    }

    if (dem >= 5) {
        return 0;
    }

    return 1;
}


void them_benh_nhan() {

    if (n >= MAX) {
        printf("\nHang doi da day! Khong the them.\n");
        return;
    }

    printf("\n========== TIEP NHAN BENH NHAN ==========\n");

    printf("Nhap ten benh nhan: ");
    fgets(ten_benh_nhan[n], TEN_MAX, stdin);
    xoa_enter(ten_benh_nhan[n]);

    printf("Nhap tuoi: ");
    scanf("%d", &tuoi[n]);

    printf("Co BHYT? (1-Co, 0-Khong): ");
    scanf("%d", &bao_hiem[n]);

    if (bao_hiem[n] != 0 && bao_hiem[n] != 1) {
        bao_hiem[n] = 0;
    }

    printf("Co mang thai? (1-Co, 0-Khong): ");
    scanf("%d", &mang_thai[n]);

    if (mang_thai[n] != 0 && mang_thai[n] != 1) {
        mang_thai[n] = 0;
    }

    printf("Nhap ma bac si (1-10): ");
    scanf("%d", &bac_si[n]);

    printf("Nhap khung gio (1-10): ");
    scanf("%d", &khung_gio[n]);

    if (!kiem_tra_tai_bac_si(bac_si[n], khung_gio[n])) {

        printf("\nBac si %d - khung gio %d da du 5 benh nhan!\n",
               bac_si[n], khung_gio[n]);

        printf("Khong the dang ky them.\n");

        return;
    }
    so_thu_tu[n] = n + 1;

    cap_nhat_uu_tien(n);

    cap_nhat_phi(n);
    if (uu_tien[n] == 1) {

        int i;

        for (i = n; i > 0; i--) {

            if (uu_tien[i - 1] == 0) {

                so_thu_tu[i] = so_thu_tu[i - 1];

                strcpy(ten_benh_nhan[i],
                       ten_benh_nhan[i - 1]);

                tuoi[i] = tuoi[i - 1];
                uu_tien[i] = uu_tien[i - 1];
                bao_hiem[i] = bao_hiem[i - 1];
                mang_thai[i] = mang_thai[i - 1];
                phi_kham[i] = phi_kham[i - 1];
                bac_si[i] = bac_si[i - 1];
                khung_gio[i] = khung_gio[i - 1];

            } else {
                break;
            }
        }
        int pos = i;

        so_thu_tu[pos] = n + 1;
    }

    n++;

    for (int i = 0; i < n; i++) {
        so_thu_tu[i] = i + 1;
    }

    printf("\nDang ky thanh cong!\n");
}


void hien_thi_danh_sach() {

    int i;

    if (n == 0) {
        printf("\nDanh sach dang rong!\n");
        return;
    }

    printf("\n================ DANH SACH BENH NHAN ================\n");

    for (i = 0; i < n; i++) {

        printf("\nSTT: %d\n", so_thu_tu[i]);
        printf("Ten: %s\n", ten_benh_nhan[i]);
        printf("Tuoi: %d\n", tuoi[i]);

        if (uu_tien[i] == 1) {
            printf("Dien: UU TIEN\n");
        } else {
            printf("Dien: THUONG\n");
        }

        if (bao_hiem[i] == 1) {
            printf("BHYT: CO\n");
        } else {
            printf("BHYT: KHONG\n");
        }

        if (mang_thai[i] == 1) {
            printf("Mang thai: CO\n");
        } else {
            printf("Mang thai: KHONG\n");
        }

        printf("Bac si: %d\n", bac_si[i]);
        printf("Khung gio: %d\n", khung_gio[i]);

        printf("Phi kham: %d VND\n", phi_kham[i]);
    }
}


void sua_benh_nhan() {

    int stt;
    int i;
    int tim_thay = 0;

    printf("\nNhap so thu tu can sua: ");
    scanf("%d", &stt);

    for (i = 0; i < n; i++) {

        if (so_thu_tu[i] == stt) {

            tim_thay = 1;

            printf("\nNhap ten moi: ");

            getchar();

            fgets(ten_benh_nhan[i],
                  TEN_MAX,
                  stdin);

            xoa_enter(ten_benh_nhan[i]);

            printf("Nhap tuoi moi: ");
            scanf("%d", &tuoi[i]);

            printf("Nhap BHYT moi (1-Co, 0-Khong): ");
            scanf("%d", &bao_hiem[i]);

            if (bao_hiem[i] != 0 &&
                bao_hiem[i] != 1) {

                bao_hiem[i] = 0;
            }

            printf("Nhap mang thai (1-Co, 0-Khong): ");
            scanf("%d", &mang_thai[i]);

            if (mang_thai[i] != 0 &&
                mang_thai[i] != 1) {

                mang_thai[i] = 0;
            }

            cap_nhat_uu_tien(i);
            cap_nhat_phi(i);

            printf("\nCap nhat thanh cong!\n");

            break;
        }
    }

    if (tim_thay == 0) {
        printf("\nKhong tim thay so thu tu %d!\n", stt);
    }
}

void xoa_benh_nhan() {

    int stt;
    int i;
    int pos = -1;

    printf("\nNhap so thu tu can xoa: ");
    scanf("%d", &stt);

    for (i = 0; i < n; i++) {

        if (so_thu_tu[i] == stt) {
            pos = i;
            break;
        }
    }

    if (pos == -1) {
        printf("\nKhong tim thay benh nhan!\n");
        return;
    }

    for (i = pos; i < n - 1; i++) {

        so_thu_tu[i] = so_thu_tu[i + 1];

        strcpy(ten_benh_nhan[i],
               ten_benh_nhan[i + 1]);

        tuoi[i] = tuoi[i + 1];

        uu_tien[i] = uu_tien[i + 1];

        bao_hiem[i] = bao_hiem[i + 1];

        mang_thai[i] = mang_thai[i + 1];

        phi_kham[i] = phi_kham[i + 1];

        bac_si[i] = bac_si[i + 1];

        khung_gio[i] = khung_gio[i + 1];
    }

    n--;

    for (i = 0; i < n; i++) {
        so_thu_tu[i] = i + 1;
    }

    printf("\nXoa benh nhan thanh cong!\n");
}


void tim_theo_stt() {

    int stt;
    int i;

    printf("\nNhap so thu tu: ");
    scanf("%d", &stt);

    for (i = 0; i < n; i++) {

        if (so_thu_tu[i] == stt) {

            printf("\n========== THONG TIN ==========\n");

            printf("STT: %d\n", so_thu_tu[i]);
            printf("Ten: %s\n", ten_benh_nhan[i]);
            printf("Tuoi: %d\n", tuoi[i]);

            if (uu_tien[i] == 1)
                printf("Dien: UU TIEN\n");
            else
                printf("Dien: THUONG\n");

            if (bao_hiem[i] == 1)
                printf("BHYT: CO\n");
            else
                printf("BHYT: KHONG\n");

            printf("Phi: %d VND\n", phi_kham[i]);

            return;
        }
    }

    printf("\nKhong tim thay!\n");
}
void tim_theo_ten() {

    char ten_can_tim[TEN_MAX];

    int i;
    int tim_thay = 0;

    getchar();

    printf("\nNhap ten can tim: ");
    fgets(ten_can_tim,
          TEN_MAX,
          stdin);

    xoa_enter(ten_can_tim);

    for (i = 0; i < n; i++) {

        if (strcmp(ten_benh_nhan[i],
                   ten_can_tim) == 0) {

            printf("\n========== TIM THAY ==========\n");

            printf("STT: %d\n", so_thu_tu[i]);
            printf("Ten: %s\n", ten_benh_nhan[i]);
            printf("Tuoi: %d\n", tuoi[i]);

            if (uu_tien[i] == 1)
                printf("Dien: UU TIEN\n");
            else
                printf("Dien: THUONG\n");

            if (bao_hiem[i] == 1)
                printf("BHYT: CO\n");
            else
                printf("BHYT: KHONG\n");

            printf("Phi kham: %d VND\n",
                   phi_kham[i]);

            tim_thay = 1;
        }
    }

    if (tim_thay == 0) {
        printf("\nKhong tim thay benh nhan!\n");
    }
}

void menu_tim_kiem() {

    int choice;

    printf("\n========== TIM KIEM ==========\n");
    printf("1. Tim theo so thu tu\n");
    printf("2. Tim theo ten\n");
    printf("0. Quay lai\n");

    printf("Nhap lua chon: ");
    scanf("%d", &choice);

    switch (choice) {

        case 1:
            tim_theo_stt();
            break;

        case 2:
            tim_theo_ten();
            break;

        case 0:
            break;

        default:
            printf("\nLua chon khong hop le!\n");
    }
}

int main() {

    int choice;

    do {

        printf("\n\n============================================\n");
        printf("      MEDCARE CLINIC - QUAN LY KIOSK\n");
        printf("============================================\n");

        printf("1. Tiep nhan benh nhan moi\n");
        printf("2. Hien thi danh sach hang doi\n");
        printf("3. Cap nhat thong tin\n");
        printf("4. Huy so thu tu\n");
        printf("5. Tim kiem benh nhan\n");
        printf("0. Thoat\n");

        printf("============================================\n");
        printf("Nhap lua chon: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                getchar();
                them_benh_nhan();
                break;

            case 2:
                hien_thi_danh_sach();
                break;

            case 3:
                sua_benh_nhan();
                break;

            case 4:
                xoa_benh_nhan();
                break;

            case 5:
                menu_tim_kiem();
                break;

            case 0:
                printf("\nKet thuc chuong trinh!\n");
                break;

            default:
                printf("\nLua chon khong hop le!\n");
        }

    } while (choice != 0);

    return 0;
}
