vector<int> finalPrices(vector<int>& prices) {
    vector<int> ret(prices);
    vector<int> s;

    for (int i=0; i<prices.size(); ++i) {
        while (s.size() && prices[s[s.size()-1]] >= prices[i]) {
            ret[s[s.size()-1]] +=  - prices[i];
            s.pop_back();
        }

        s.push_back(i);
    }

    return ret;
}
