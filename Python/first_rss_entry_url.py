#!/usr/bin/env python3

import sys
import urllib3
import xml.etree.ElementTree as ET

http = urllib3.PoolManager()
response = http.request('GET',sys.argv[1])

if response.status == 200:

    try:
        tree = ET.fromstring(response.data.decode('utf-8'))
        firstentry = tree.find('{http://www.w3.org/2005/Atom}entry')
        appliedarr = {}
        for child in firstentry:
            shortattr = child.tag.replace('{http://www.w3.org/2005/Atom}','')
            appliedarr.update({shortattr : child.text})
        print('<h2>'+appliedarr['title']+'</h2>'
              +'<p>'+appliedarr['summary']
              + ' Updated: ' + appliedarr['updated']
              +' <a href="'+appliedarr['id']
              + '">Read More</a></p><hr style="margin-top: 50px;" />')
        sys.exit(0)
    except Exception as e:
        print(e)
        sys.exit(1)

else:
    print('Request failed.')
    sys.exit(2)
