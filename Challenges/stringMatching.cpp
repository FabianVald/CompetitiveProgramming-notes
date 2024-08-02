#include <iostream>
#include <vector>
#include <string>

std::vector<int> computeLPSArray(const std::string& needle) {
    int m = needle.length();
    std::vector<int> lps(m, 0);
    int length = 0;  // Longitud del prefijo más largo que también es sufijo
    int i = 1;

    while (i < m) {
        if (needle[i] == needle[length]) {
            length++;
            lps[i] = length;
            i++;
        } else {
            if (length != 0) {
                length = lps[length - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

int KMPCountOccurrences(const std::string& haystack, const std::string& needle) {
    int n = haystack.length();
    int m = needle.length();
    if (m == 0) return 0;

    std::vector<int> lps = computeLPSArray(needle);
    int i = 0; // Índice para haystack
    int j = 0; // Índice para needle
    int count = 0;

    while (i < n) {
        if (needle[j] == haystack[i]) {
            i++;
            j++;
        }
        if (j == m) {
            count++;
            j = lps[j - 1];
        } else if (i < n && needle[j] != haystack[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
    return count;
}

int main() {
    std::string B;
    std::string A;
    std::cin >> B >> A;

    int occurrences = KMPCountOccurrences(B, A);
    std::cout <<occurrences;

    return 0;
}