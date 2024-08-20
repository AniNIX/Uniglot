#!/usr/bin/env python3

import sys
import xml.etree.ElementTree as ET

try:
    tree = ET.parse(sys.argv[1])
    firstentry = tree.find('{http://www.w3.org/2005/Atom}entry')
    appliedarr = {}
    for child in firstentry:
        shortattr = child.tag.replace('{http://www.w3.org/2005/Atom}','')
        appliedarr.update({shortattr : child.text})
    print('<h2>'+appliedarr['title']+'</h2>'
          +'<p>'+appliedarr['summary']
          + ' <br/><br/><b>Updated: ' + appliedarr['updated']  + '</b> '
          +' <a href="'+appliedarr['id']
          + '">Read More</a></p><hr style="margin-top: 50px;" />')
    sys.exit(0)
except Exception as e:
    print(e)
    sys.exit(1)
