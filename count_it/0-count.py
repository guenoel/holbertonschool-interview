#!/usr/bin/python3
'''Get ALL hot posts'''
import requests

BASE_URL = 'http://reddit.com/r/{}/hot.json'

def count_words(subreddit, word_list):
    hot_list=[]
    after=None

    # Set up headers and parameters for the HTTP request
    headers = {}
    params = {'limit': 100}

    while(after != "STOP"):
        # there is an ID of the last processed post add it to the request parameter
        if isinstance(after, str) and after != "STOP":
            params['after'] = after

        # Make the request to the Reddit API
        response = requests.get(BASE_URL.format(subreddit),
                                headers=headers, params=params)

        # Check if the request was successful (status code 200)
        if response.status_code != 200:
            break

        data = response.json().get('data', {})

        # Get the ID of the last post for the next request
        after = data.get('after', 'STOP')
        if not after:
            after = "STOP"

        for post in data.get('children', []):
            hot_list.append(post.get('data', {}).get('title'))

    # Initialize a dictionary to count the frequency of each keyword
    count = {word: 0 for word in word_list}

    # Iterate over each post title and count occurrences of each keyword
    for title in hot_list:
        for word in word_list:
            for title_word in title.lower().split():
                if title_word == word.lower():
                    count[word] += 1

    # Filter keywords with count greater than zero
    count = {k: v for k, v in count.items() if v > 0}

    # Sorted in descending order by frequency ,alphabetically in case of ties
    words = list(count.keys())
    for word in sorted(words, reverse=True, key=lambda k: count[k]):
        print("{}: {}".format(word, count[word]))