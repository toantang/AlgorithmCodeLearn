#include <bits/stdc++.h>
#define MAX 150
using namespace std;

const string x[] = {"red", "violet", "orange", "yellow", "green", "indigo", "blue"};
int a[MAX]; // mảng lưu trữ số kí tự trong mảng x[]
int ans = INT_MAX;
int cnt[MAX];

void countCharRainbow() {
    string s;
    for (int i = 0; i < 7; i++) {
        s = s + x[i];
    }
    int len = s.size();
    
    for (int i = 0; i <= 122; i++) {
        a[i] = 0;
    }
    for (int i = 97; i <= 122; i++) {
        for (int j = 0; j < len; j++) {
            if (s[j] == i) {
                a[i] = a[i] + 1;
            }
        }
    }

    for (int i = 97; i <= 122; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void countRainbow(string str) {
    int len = str.size();
    for (int i = 0; i < MAX; i++) {
        cnt[i] = 0;
    }
    for (int i = 0; i < len; i++) {
        int val = str[i];
        //cout << val << " ";
        cnt[val]++;
    }
    cout << endl;
    for (int i = 97; i <= 122; i++) {
        cout << cnt[i] << " ";
    }
    cout << endl;
    for (int i = 97; i <= 122; i++) {
        if (a[i] != 0) {
            cnt[i] = cnt[i]/a[i];
            if (cnt[i] < ans) {
                ans = cnt[i];
            }
        }
    }
}
int main() {
    countCharRainbow();
    string str = "deonlvgvliniebrngooeugdieoletrwdeeontoyaiillnddrigrogieie";
    //string str = "ngegooglnonnaugrnyeniroowealrlrerndrgyneeouerndeitnneboeuigwoielngiblboreoeogrlaolordwielvleeeiaylaelueweoelaloubgerllvegdulwonoaebigdorggwlnlgeriyldleeoenybbrelreuydengeegotiaao";
    //string str = "rarnnnnrlerlloadeedenelgnuigrvidnueelidgnnbgtiuoirigterllenrogrwdedeleeneleindydebeidvieovgrdlgeuridtgerroroiloyrobwegdeeneldnowioegeoyooenngageieiglrdeoregeoereebig";
    //string str = "owroeereibuleudrorlyinoyvegglilelilioylueoeelelilglreargdeoytloinonryntaoedleuedeeereregrieuntbobweredegwuiodellweoerelbbdirrleerenddnyitwelollalvnnveitgveieoeoetbennuedaolrvgoleittbgliowlvonveieddeoeeganeourrlybdlgraryoyvtbleigrwoteglyieneltgndudgwongenruevdbegouelvaolneeeoioluuonuebabeieelgloindgiliooooweiglieleeeledleldteoilbelwvoveeeenwlnglellaviorneeiodbwiwegylniwioybtrureetellooegrllduuglyuoogldyribeirlwtoeivlentybellanerreglreonlorvlonllgylolotlglvldnggeogiodobelioorollrgengewvreneeydoeigeeeriiwweydnoenevieeralrtdnr";
    //string str = "egbiurlybeilurlelilwoerrwunllnneiellneeolboeieodrgenubnabgyldeorwgelbdgidaiwbldldeeldgrrgreeyllobyeeworolleloyrogeeeluoboelyewlloogoleielaeewlnobyguruwgvieayeborlglirlyyodlygweaeueeelgbrnrrwydlydoeyelnnwbodoeedbynnoywrieugeoeyigayneeernourrereoebewwonebddnlnyeellergbgndenluinluulnluowgrueuggnwlweeueioendiduaereewebnlgyyugralonwndwurogeeelranedeyllddleloeloweerrlgaellwleblbweeerbwyrobaeeeelwuylbeelrwloneyeleiaoreybllnngruruorwleednellegeeeyreugyeuoiooglalyyeeeellerlogneelunelroldddeuleeguoooabrwllnayydogrlerlnrolenoaiirbnbgdarurlbeenuiwddeybireeoeyoereoergyualgualedneiowwwligolliwwrilldllleuolelbugweooalooooweaidneelnougrlorbugeyibuerlogreeenowirieegelouoeeurrbenreigoblbdlrobgewbllrdealeyoilllrlooenllogdiyonoorgeeawnedenderoygiglegyywgeeyddalggeudtenuygdlonedrgignnonedeleoreoeoleooygagwgnlynyglebelenoweebnerleiuyelwgouugleiielglegybvnnubleldnlgddagblrntbraoleedolwywruiuelolelyleubrielualliwoeogodwlydloddlnrwldlogbengblyleiineilrwbluaoegblyylrwnwrlnglaaegidnlyenollwlelrrlreebyoienregydlieeeidbbrnnguneglieoeeoblllnlelnyoiwelndeouayennwogoreeneaeooeeoogoeeuaunieodrdnoobnueglebyllaoeodbbgdywrngnenieegdrgoelleigibwgorololroddlreeyegrudeyegonolroggglloolrarnnlogrergrgdonaeeelleyeuobeeeueaioibdudergnunebelbeawaooolegonueiollordibearbreaoowdleeiiuiyeeonlgellidlewynlleireleaaouooeleoedninleleererolwwwrnnrolndnlorilegleeuglnrgiggnrnrloebnaolreebudebnegnlyeeliyeguoyuoeoeoyeeiloinogwlwlloeoeueeloyellndgagunrgoowleuwdloellldlwlyreideloiewlwalwlrllegriegreoblngulynbwaginolwelroywgleoneeoidngywgryawleoenyeolnbyoelleiieoorlllilybagudwieibewrglnborobwwegyoewoeug";
    countRainbow(str);
    cout << ans << endl;
    return 0;
}