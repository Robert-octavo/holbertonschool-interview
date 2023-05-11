#!/usr/bin/python3
''' Write a recursive function that queries the Reddit API'''
import requests


def count_words(subreddit, word_list, after="", word_dic={}):
    ''' count words '''
    if not word_dic:
        for word in word_list:
            word_dic[word] = 0
    if after is None:
        word_list = [[key, value] for key, value in word_dic.items()]
        word_list = sorted(word_list, key=lambda x: (-x[1], x[0]))
        for word in word_list:
            if word[1]:
                print("{}: {}".format(word[0].lower(), word[1]))
        return None
    url = "https://www.reddit.com/r/{}/hot.json".format(subreddit)
    headers = {"User-Agent": "linux:1:v1.0 (by /u/heimer_r)"}
    params = {"limit": 100, "after": after}
    res = requests.get(url, headers=headers, params=params,
                       allow_redirects=False)
    if res.status_code != 200:
        return None
    data = res.json().get("data")
    after = data.get("after")
    children = data.get("children")
    for child in children:
        title = child.get("data").get("title").lower().split(" ")
        for word in word_list:
            word_dic[word] += title.count(word.lower())
    count_words(subreddit, word_list, after, word_dic)
