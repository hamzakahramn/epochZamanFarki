#include <stdio.h>
#include <time.h>

struct DateTime {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
};

union EpochTime {
    time_t epoch;
    struct DateTime datetime;
};

time_t convertToEpoch(struct DateTime dt) {
    struct tm t;
    t.tm_year = dt.year - 1900;
    t.tm_mon = dt.month - 1;
    t.tm_mday = dt.day;
    t.tm_hour = dt.hour;
    t.tm_min = dt.minute;
    t.tm_sec = dt.second;
    t.tm_isdst = -1; // Daylight saving time flag

    return mktime(&t);
}

int main() {
    struct DateTime dt1, dt2;
    union EpochTime t1, t2;

    // Kullanýcýdan ilk tarih ve saati alýn
    printf("Birinci tarih ve saati giriniz (yyyy mm dd hh mm ss): ");
    scanf("%d %d %d %d %d %d", &dt1.year, &dt1.month, &dt1.day, &dt1.hour, &dt1.minute, &dt1.second);

    // Kullanýcýdan ikinci tarih ve saati alýn
    printf("Ýkinci tarih ve saati giriniz (yyyy mm dd hh mm ss): ");
    scanf("%d %d %d %d %d %d", &dt2.year, &dt2.month, &dt2.day, &dt2.hour, &dt2.minute, &dt2.second);

    // Struct'larý epoch zamanýna çevir
    t1.epoch = convertToEpoch(dt1);
    t2.epoch = convertToEpoch(dt2);

    // Zaman farkýný hesapla
    double diff = difftime(t2.epoch, t1.epoch);

    // Sonuçlarý ekrana yazdýr
    printf("Birinci tarih epoch zamaný: %ld\n", t1.epoch);
    printf("Ýkinci tarih epoch zamaný: %ld\n", t2.epoch);
    printf("Ýki tarih arasýndaki zaman farký: %.2f saniye\n", diff);

    return 0;
}

