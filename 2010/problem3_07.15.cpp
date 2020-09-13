
// Да се напише функция, която по зададен масив от низове намира най-големия брой низове от масива,
// които са анаграми помежду си. Един низ е анаграма на друг,
// ако е съставен от същите символи, но в разбъркан ред, като това означава,
// че за да са анаграми два низа трябва всеки от символите на първия да се среща
// точно толкова пъти и във втория.
// Например низовете asdff и fsdaf са анаграми един на друг, докато низовете asdff и ааfsd не са.

bool areAnagrams(char *s1, char *s2) {
    int counts1[26] = {0}, counts2[26] = {0};

    char *c1 = s1, *c2 = s2;
    while(*c1 != '\0' && *c2 != '\0') {
        counts1[*c1 - 'a']++;
        counts2[*c2 - 'a']++;
        c1++;
        c2++;
    }
    if (*c1 != '\0' || *c2 != '\0') {
        return false;
    }
    for(int i = 0; i < 26; i++) {
        if(counts1[i] != counts2[i]) {
            return false;
        }
    }
    return true;
}

int maxAnagrams(char **strings, int n) {
    int max = 0;

    for(int i = 0; i < n - 1; i++) {
        char *curr = strings[i];
        int count = 1;
        for(int j = i + 1; j < n; j++) {
            char *other = strings[j];
            if(areAnagrams(curr, other)) {
                count++;
            }
        }
        if (count > max) {
            max = count;
        }
    }

    return max;
}