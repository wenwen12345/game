# include <cstdlib>
# include <ctime>
# include <string>
# include <vector>
# include <cctype>
# include <iostream>
# include <sqlite3.h>
using namespace std;

int randoms()
{
	int RandomNumber;
	srand((unsigned)time(nullptr));
	RandomNumber = rand() % 100 + 1;//生成1~100随机数
	return RandomNumber;
}
class numgame
{
    private:
    int input_number;
    int answer;
    string g;
    int conn;
    sqlite3 *db;
    public:
    void init()
    {
        this->answer = randoms();
        this->conn = sqlite3_open("game.db",&db);
    };
    void input()
    {
        for (;;)
        {
            cout << "input a number in 1-100:";
            getline(cin,g);
            char const *s = g.c_str();
            if(g=="q"||g=="quit")
            {
                exit(0);
            }
            if ((isdigit(*s)))
            {
                this->input_number = stoi(g);
                return;
            }
        }
    }
    void cmp()
    {
        for(;;)
            {
                this->input();
                if(this->input_number<this->answer)
                {
                    cout << "small" << endl;
                };
                if(this->input_number > this->answer)
                {
                    cout << "big" << endl;
                };
                if(this->input_number == this->answer)
                {
                    cout << "good job";
                    exit(0);
    	        };
            };
    };
    void delobj()
    {
        sqlite3_close(this->db);
    }
    void run()
    {
        this->init();
        this->cmp();
        this->delobj();
    };
};