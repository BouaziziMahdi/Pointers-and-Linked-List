#include <iostream>
#include <string>
/*
1ère Etape: Nlawwej 3al parentheses el akhranin mel dakhel.
2ème Etape: Na3ks el caractères elli bin el parentheses en utilisant swap bel deux pointeurs.
3ème Etape: Nna7i el parentheses el barra baad ma na3ksna el caractères.
4ème Etape: Ne3awed na3mel el processus hadha jusqu'à ma yab9ach parentheses fil string.
*/
#include <iostream>
#include <string>
#include <algorithm>

class Solution {
public:
    std::string reverseParentheses(std::string s) {
        int n = s.size();

        while (true) {
            int open = -1;
            int close = -1;

            // Trouver la parenthèse ouvrante la plus interne
            for (int i = 0; i < n; ++i) {
                if (s[i] == '(') {
                    open = i;
                } else if (s[i] == ')') {
                    close = i;
                    break;
                }
            }

            // Si aucune parenthèse ouvrante ou fermante n'est trouvée, on sort de la boucle
            if (open == -1 || close == -1) {
                break;
            }

            // Utiliser deux pointeurs pour inverser les caractères entre les parenthèses
            int left = open + 1;
            int right = close - 1;
            while (left < right) {
                std::swap(s[left], s[right]);
                left++;
                right--;
            }

            // Supprimer les parenthèses après inversion
            s.erase(s.begin() + close);
            s.erase(s.begin() + open);

            // Mettre à jour la taille de la chaîne de caractères
            n = s.size();
        }

        return s;
    }
};

int main() {
    Solution solution;
    std::string s1 = "(abcd)";
    std::string s2 = "(u(love)i)";
    std::string s3 = "(ed(et(oc))el)";
    std::cout << solution.reverseParentheses(s1) << std::endl; // Output: "dcba"
    std::cout << solution.reverseParentheses(s2) << std::endl; // Output: "iloveu"
    std::cout << solution.reverseParentheses(s3) << std::endl; // Output: "leetcode"
    return 0;
}
