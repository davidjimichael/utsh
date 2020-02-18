#include "lib.h"

int main(int argc, char *argv[], char *arge[])
{
    vector<string> resrc;
    resrc.assign(arge, arge + ENV_SIZE);

    string password;
    cout << "PROFILE: " << getenv("USERPROFILE") << endl
         << "PASSWORD: ";
    std::getline(std::cin, password);

    resrc.push_back(get_exe_path());
    resrc.push_back(password);

    string file = getenv("USERPROFILE") + SEP + "Desktop" + SEP + ".ourshrc";
    std::ofstream fout(file);

    for (auto i = resrc.begin(); i != resrc.end(); ++i)
    {
        fout << *i << endl;
    }

    fout.close();

    return 0;
}