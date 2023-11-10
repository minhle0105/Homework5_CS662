#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class PrimitiveElementGenerator
{
public:
    vector<int> find_primitive_elements(int p)
    {
        vector<int> primitive_elements;
        for (int i = 2; i < p; ++i)
        {
            if (is_primitive_element(i, p))
            {
                primitive_elements.push_back(i);
            }
        }

        return primitive_elements;
    }

private:
    bool is_primitive_element(int n, int p)
    {
        if (n % p == 0)
        {
            return false;
        }

        unordered_set<int> powers;
        int x = 1;

        for (int i = 0; i < p - 1; ++i)
        {
            x = (x * n) % p;
            if (powers.find(x) != powers.end())
            {
                return false;
            }
            powers.insert(x);
        }

        return powers.size() == p - 1;
    }
};

class EulerTotientGenerator
{
public:
    vector<int> generate(const vector<int> &nums)
    {
        vector<int> res;
        for (int num : nums)
        {
            if (isPrime(num))
            {
                res.push_back(num - 1);
            }
            else
            {
                double euler = num;
                for (int i = 2; i < num; ++i)
                {
                    if (num % i == 0 && isPrime(i))
                    {
                        double a = static_cast<double>(1) / i;
                        euler *= (1 - a);
                    }
                }
                res.push_back(static_cast<int>(euler));
            }
        }

        return res;
    }

private:
    bool isPrime(int n)
    {
        if (n == 2)
        {
            return true;
        }
        for (int i = 2; i <= sqrt(n); ++i)
        {
            if (n % i == 0)
            {
                return false;
            }
        }

        return true;
    }
};

int main()
{
    PrimitiveElementGenerator peg;
    int p;
    cout << "Enter p: " << endl;
    cin >> p;
    vector<int> primitive_elements = peg.find_primitive_elements(p);
    cout << "Primitive elements of " << to_string(p) << " are: " << endl;
    for (int element : primitive_elements)
    {
        cout << element << " ";
    }
    cout << endl;

    EulerTotientGenerator etg;
    vector<int> nums = {831, 833, 834, 835, 837, 839};
    vector<int> res = etg.generate(nums);
    for (int i = 0; i < nums.size(); ++i)
    {
        cout << "Euler totient of " << to_string(nums[i]) << " is " << to_string(res[i]) << endl;
    }
    cout << endl;
    return 0;
}