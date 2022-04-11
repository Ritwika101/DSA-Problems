void printSubsequence(string input, string output)
{
    if (input.empty()) {
        cout << output << endl;
        return;
    }
    printSubsequence(input.substr(1,input.length()-1), output + input[0]);
    printSubsequence(input.substr(1,input.length()-1), output);
}
