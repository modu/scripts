#!/usr/bin/python
# -*- coding: UTF-8 -*-

import vk_auth
from vk_auth import call_api

from vk_config import user_params

import time

import json
import urllib2
from urllib import urlencode
import os
import getpass
import sys



def get_albums(user_id, token):
    return call_api("photos.getAlbums", [("uid", user_id)], token)

def get_photos_urls(user_id, album_id, token):
    photos_list = call_api("photos.get", [("uid", user_id), ("aid", album_id)], token)
    result = []
    for photo in photos_list:
        #Choose photo with largest resolution
        if "src_xxbig" in photo:
            url = photo["src_xxbig"]
        elif "src_xbig" in photo:
            url = photo["src_xbig"]
        else:
            url = photo["src_big"]
        result.append(url)
    return result

def save_photos(urls, directory):
    if not os.path.exists(directory):
        os.mkdir(directory)
    names_pattern = "%%0%dd.jpg" % len(str(len(urls)))
    for num, url in enumerate(urls):
        filename = os.path.join(directory, names_pattern % (num + 1))
        print "Downloading %s" % filename
        open(filename, "w").write(urllib2.urlopen(url).read())


email = user_params['email']#raw_input("Email: ")
password = user_params['password']#getpass.getpass()

client_id = "2951857" # Vk application ID
token, user_id = vk_auth.auth(email, password, client_id, "offline,photos,status,friends,audio")
#print token
#print call_api('status.set', [('text', 'First Using VK.api')], token)
'''
li = call_api('friends.get', [('uid', user_id), ('fields', 'first_name')], token)
for x in li:
    #print x['first_name'], x['uid']
    try:
        print x['uid'], len(call_api('audio.get', [('uid', x['uid'])], token))
    except:
        print 'unable', x['uid']
    #time.sleep(1)


albums = get_albums(user_id, token)
#print "\n".join("%d. %s" % (num + 1, album["title"]) for num, album in enumerate(albums))
choice = -1
while choice not in xrange(len(albums)):
    choice = int(raw_input("Choose album number: ")) - 1
if not directory:
    directory = albums[choice]["title"]
photos_urls = get_photos_urls(user_id, albums[choice]["aid"], token)
save_photos(photos_urls, directory)
'''
