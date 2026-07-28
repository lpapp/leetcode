#include <cassert>
#include <string>

using namespace std;

class Solution {
    long long countPerms(int remaining, int freq[26], long long cap) {
        long long result = 1;
        int numerator = remaining;
        for (int i = 0; i < 26; ++i) {
            const int k = freq[i], n_start = numerator;
            const int effective_k = min(k, n_start - k);
            long long binom = 1;
            for (int j = 1; j <= effective_k; ++j) {
                binom = binom * (n_start - j + 1) / j;
                if (binom > cap / result) return cap + 1;
            }
            result *= binom;
            if (result > cap) return cap + 1;
            numerator -= k;
        }
        return result;
    }
public:
    string smallestPalindrome(string s, int k) {
        const int n = s.size(), half = n / 2;
        int freq[26] = {};
        for (int i = 0; i < half; ++i) ++freq[s[i] - 'a'];
        char mid = n & 1 ? s[half] : 0;
        long long rank = k - 1;
        if (countPerms(half, freq, rank) <= rank) return "";
        string left(half, ' ');
        int remaining = half;
        for (int pos = 0; pos < half; ++pos) {
            for (int c = 0; c < 26; ++c) {
                if (!freq[c]) continue;
                --freq[c];
                --remaining;
                long long count = countPerms(remaining, freq, rank);
                if (count > rank) {
                    left[pos] = 'a' + c;
                    break;
                }
                rank -= count;
                ++freq[c];
                ++remaining;
            }
        }
        string res = left;
        if (mid) res += mid;
        for (int i = half - 1; i >= 0; --i) res += left[i];
        return res;
    }
};


int main()
{
    Solution s;
    assert(s.smallestPalindrome("abba", 2) == "baab");
    assert(s.smallestPalindrome("aa", 2) == "");
    assert(s.smallestPalindrome("bacab", 1) == "abcba");
    assert(s.smallestPalindrome("ghdhhdhg", 5) == "ghdhhdhg");
    assert(s.smallestPalindrome("bztgradbzuzlvcpvkckivfbgxyqcseeofkfxlzxmyoytsgeqghtuaxdlgzheumvprockzywlwkjxowyfcbxunnquawtpddqjepzgozkbczauucmfxaegijcfgzqgtunzqskscnaftnwnahghgaufzmgktucamnriwbltznnwgweqnqrksursliujouyjzsbtbwywahhpguqinjcmoxfyqcrktavfntqrifiqtgbnzghpfxwxzsfnzrzwjnviqthizmskiojeaklepnffmhlnnwbmahvqdsmcajtzftgxniaovtgyeqiczmsqcjreiprcizwukdwjludfnchoqesfgbyhrosvbsbtnpezzhnmoscpiwsgftvzkuwmxkbddsczakzlqnyxnutecofkuaclofeilrymucaitluimekrnzdgcgtpcssjixobmfuistgjtrnykltclmhkgkdfxzomxzmasoekvdabetjhboxlamcsjmhglcfrtxdxxjmmwhffrwfqlhvpbbpqjnshftsyjwaesknyufsoxehixzcaewcuhtoufrcckcxtviesroehxedzgnusmjpetutehgfcveqzvnlccvcujjkpuailbosbpnypkoyjqgjaxsvbulgibeneblzzbeadenfpzmyclzmslskfxjlipnnstcndkajuvjegxtndawfvjemgvqxonlhlxjiapahyorltsrzlzohnaqmwtwmshomtxfsjbhrempxcohkcradcpelbzqeswupbonknunlfsuszjhhdkktgbgedomzvehsgddfvknxcqfrgcpegydweznllumensiwlugjxgwzufxzzalzniigcwyvnbwxsikylufniucsnxpfbrxiacfldjoosabsfbusuaampudlftbswmnznodupstdcfvbmcrnoyrvmzzpledsrcfxswdzibdscnshgtejvwhdgyoggysxdrjqcwlcvyfhbgnbkvsfdzguqsjltmgvnunvgmtljsqugzdfsvkbngbhfyvclwcqjrdxsyggoygdhwvjetghsncsdbizdwsxfcrsdelpzzmvryonrcmbvfcdtspudonznmwsbtfldupmaausubfsbasoojdlfcaixrbfpxnscuinfulykisxwbnvywcgiinzlazzxfuzwgxjgulwisnemullnzewdygepcgrfqcxnkvfddgshevzmodegbgtkkdhhjzsusflnunknobpuwseqzblepcdarckhocxpmerhbjsfxtmohsmwtwmqanhozlzrstlroyhapaijxlhlnoxqvgmejvfwadntxgejvujakdnctsnnpiljxfkslsmzlcymzpfnedaebzzlbenebiglubvsxajgqjyokpynpbsobliaupkjjucvcclnvzqevcfghetutepjmsungzdexheorseivtxckccrfuothucweaczxihexosfuynkseawjystfhsnjqpbbpvhlqfwrffhwmmjxxdxtrfclghmjscmalxobhjtebadvkeosamzxmozxfdkgkhmlctlkynrtjgtsiufmboxijsscptgcgdznrkemiultiacumyrliefolcaukfocetunxynqlzkazcsddbkxmwukzvtfgswipcsomnhzzepntbsbvsorhybgfseqohcnfduljwdkuwzicrpierjcqsmzciqeygtvoainxgtfztjacmsdqvhambwnnlhmffnpelkaejoiksmzihtqivnjwzrznfszxwxfphgznbgtqifirqtnfvatkrcqyfxomcjniqugphhawywbtbszjyuojuilsruskrqnqewgwnnztlbwirnmacutkgmzfuaghghanwntfancsksqznutgqzgfcjigeaxfmcuuazcbkzogzpejqddptwauqnnuxbcfywoxjkwlwyzkcorpvmuehzgldxauthgqegstyoymxzlxfkfoeescqyxgbfvikckvpcvlzuzbdargtzb", 873710) ==
    "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbccccccccccccccccccccccccccccccccccccccccccccccccccccdddddddddddddddddddddddddddddddddeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeffffffffffffffffffffffffffffffffffffffffffffffffgggggggggggggggggggggggggggggggggggggggggggggghhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiijjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkklllllllllllllllllllllllllllllllllllllllllmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnoooooooooooooooooooooooooooooooooooppppppppppppppppppppppppppppqqqqqqqqqqqqqqqqqqqqqqqqqqqqrrrrrrrrrrrrrrrrrrrrrrrrrrrrssssssssssssssssssssssssssssssssssssssssssssssssssssssstttttttttttttttttttttttttttttttttttttttttuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuvvvvvvvvvvvvvvvvvvvvvvvvvvvvvwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxyyyyyyyyyyyyyyyyyyyyyzzyzzzzzzzzyzzzzzzzzzzzzzzzzzzzzzyzzzzzzyzzzzzzzzzzzzzzzyuyzzzzzzzzzzzzzzzyzzzzzzyzzzzzzzzzzzzzzzzzzzzzyzzzzzzzzyzzyyyyyyyyyyyyyyyyyyyyyxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwvvvvvvvvvvvvvvvvvvvvvvvvvvvvvuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuutttttttttttttttttttttttttttttttttttttttttsssssssssssssssssssssssssssssssssssssssssssssssssssssssrrrrrrrrrrrrrrrrrrrrrrrrrrrrqqqqqqqqqqqqqqqqqqqqqqqqqqqqppppppppppppppppppppppppppppooooooooooooooooooooooooooooooooooonnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmlllllllllllllllllllllllllllllllllllllllllkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiihhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhggggggggggggggggggggggggggggggggggggggggggggggffffffffffffffffffffffffffffffffffffffffffffffffeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeedddddddddddddddddddddddddddddddddccccccccccccccccccccccccccccccccccccccccccccccccccccbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
    return 0;
}
