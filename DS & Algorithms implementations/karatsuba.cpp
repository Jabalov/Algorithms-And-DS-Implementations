#include<iostream>
#include<string>
#include<cmath>
#include <algorithm>
#include<iostream>

using namespace std;
int mAdjustNumsLen(string &xFirstNum, string &xSecondNum);
string mFindStrDiff(string str1, string str2);
string mFindStrSum(string str1, string str2);
string mZeropadding(string xStr, int n);
string mKaratsubaMultiply(string xFirstNum, string xSecondNum);

// Driver program to test above functions
int main()
{
    printf ("%s\n", mKaratsubaMultiply("3141592653589793238462643383279502884197169399375105820974944592", "2718281828459045235360287471352662497757247093699959574966967627").c_str());
}

string mKaratsubaMultiply(string xFirstNum, string xSecondNum)
{
    if(xFirstNum.size() < 2 || xSecondNum.size() < 2)   return (to_string(stoi(xFirstNum)*stoi(xSecondNum)));

    string lFirstNumStr = xFirstNum;
    string lSecondNumStr = xSecondNum;

    int lFirstLen = xFirstNum.size();
    int lSecondLen = xSecondNum.size();

    int n = mAdjustNumsLen(lFirstNumStr, lSecondNumStr);    

    int lFirstHalfIndex = (n / 2);
    int lSecondHalfIndex = (n - lFirstHalfIndex); // in case n = odd

    // first half and second half of first Num.
    string lFirstNumFirstHalfStr = lFirstNumStr.substr(0, lFirstHalfIndex);
    string lFirstNumSecondHalfStr = lFirstNumStr.substr(lFirstHalfIndex, lSecondHalfIndex);

    // first half and second half of second Num
    string lSecondNumFirstHalfStr = lSecondNumStr.substr(0, lFirstHalfIndex);
    string lSecondNumSecondHalfStr = lSecondNumStr.substr(lFirstHalfIndex, lSecondHalfIndex);

    // Recursively calculate the three products of inputs
    string lFirstProduct = mKaratsubaMultiply(lFirstNumFirstHalfStr, lSecondNumFirstHalfStr);
    string lSecondProduct = mKaratsubaMultiply(lFirstNumSecondHalfStr, lSecondNumSecondHalfStr);
    string lThirdProduct = mKaratsubaMultiply(mFindStrSum(lFirstNumFirstHalfStr, lFirstNumSecondHalfStr), mFindStrSum(lSecondNumFirstHalfStr , lSecondNumSecondHalfStr));

    string lFirstProductPadded = mZeropadding(lFirstProduct,2*lSecondHalfIndex);
    string lFirstSecSum = mFindStrSum(lSecondProduct,lFirstProduct);
    string lThirdFirstSecDiff = mFindStrDiff(lThirdProduct,lFirstSecSum);
    string lThirdFirstSecDiffPadded= mZeropadding(lThirdFirstSecDiff,lSecondHalfIndex);
    string llFirstProductPaddedThirdFirstSecDiffPadded = mFindStrSum(lFirstProductPadded , lThirdFirstSecDiffPadded);
    string returnedStr = mFindStrSum(llFirstProductPaddedThirdFirstSecDiffPadded , lSecondProduct);

    return returnedStr;
}

int mAdjustNumsLen(string &xFirstNum, string &xSecondNum)
{
    int lFirstLen = xFirstNum.size();
    int lSecondLen = xSecondNum.size();

    if (lFirstLen < lSecondLen)
    {
        for (int i = 0 ; i < lSecondLen - lFirstLen ; i++)      xFirstNum = '0' + xFirstNum;

        return lSecondLen;
    }
    else if (lFirstLen > lSecondLen)
    {
        for (int i = 0 ; i < lFirstLen - lSecondLen ; i++)      xSecondNum = '0' + xSecondNum;
    }
    return lFirstLen;
}

string mZeropadding(string xStr, int n)
{
    string lStr = xStr;
    for(int i = 0; i < n; i++)      lStr += "0";

    return lStr;
}
// Function for finding difference of larger numbers assuming first num is larger
string mFindStrDiff(string str1, string str2)
{
    // Take an empty string for storing result
    string str = "";

    // Calculate lengths of both string
    int n1 = str1.length(), n2 = str2.length();
    int diff = n1 - n2;

    // Initially take carry zero
    int carry = 0;

    // Traverse from end of both strings
    for (int i=n2-1; i>=0; i--)
    {
        // Do school mathematics, compute difference of
        // current digits and carry
        int sub = ((str1[i+diff]-'0') -
                   (str2[i]-'0') -
                   carry);
        if (sub < 0)
        {
            sub = sub+10;
            carry = 1;
        }
        else
            carry = 0;

        str.push_back(sub + '0');
    }

    // subtract remaining digits of str1[]
    for (int i=n1-n2-1; i>=0; i--)
    {
        if (str1[i]=='0' && carry)
        {
            str.push_back('9');
            continue;
        }
        int sub = ((str1[i]-'0') - carry);
        if (i>0 || sub>0) // remove preceding 0's
            str.push_back(sub+'0');
        carry = 0;

    }

    // reverse resultant string
    reverse(str.begin(), str.end());

    return str;
}

string mFindStrSum(string str1, string str2)
{
    if (str1.length() > str2.length())
        swap(str1, str2);

    string str = "";

    // Calculate length of both string
    int n1 = str1.length(), n2 = str2.length();
    int diff = n2 - n1;

    // Initially take carry zero
    int carry = 0;

    // Traverse from end of both strings
    for (int i=n1-1; i>=0; i--)
    {
        int sum = ((str1[i]-'0') +
                   (str2[i+diff]-'0') +
                   carry);
        str.push_back(sum%10 + '0');
        carry = sum/10;
    }

    for (int i=n2-n1-1; i>=0; i--)
    {
        int sum = ((str2[i]-'0')+carry);
        str.push_back(sum%10 + '0');
        carry = sum/10;
    }

    if (carry)
        str.push_back(carry+'0');

    reverse(str.begin(), str.end());

    return str;
}