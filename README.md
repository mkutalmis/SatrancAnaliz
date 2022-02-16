# SatrancAnaliz

Proje visual studioda oluşturuldu.
Visual studio çözümü SatrancAnaliz.sln

Header ve Cpp dosyaları SatrancAnaliz dosyasının altında.

###### Projede sadece vezir, at ve piyonun tehditleri hesaba katılmıştır.

## Kullanım Şekli : 

- Repository indir

- input.txt dosyası içine satranç tahtasındaki konumu örnekte olduğu gibi eksiksiz tam haliyle yaz.

(ekstra boşluk karakteri yada eksik taş bilgisi girilirse program hata verecektir.)

(dosya ismi input.txt değiştirilirse program hata verecektir.)

- Debug yada Release klasörleri içindeki SatrancAnaliz.exe uygulamasını çalıştır.

- Sonuç output.txt dosyasının içine yazdırılacak.

(output.txt dosyası silinirse program yenisini olusturur.)

(önceden output.txt dosyası varsa program dosyanın içeriğini silip yeni içeriği yazar.)


## Örnek input.txt

ks as fs vs ss fs -- ks
ps ps ps ps -- ps ps ps
-- -- -- -- -- as -- --
-- ab -- -- ps -- -- --
-- -- -- pb -- -- -- --
-- -- -- -- -- -- -- --
pb pb pb -- pb pb pb pb
kb -- fb vb sb fb ab kb

## Örnek output.txt

Siyah : 137.5
Beyaz : 138.5
