#!/usr/bin/env python

photos = [
     { 'score':  0 },
     { 'score':  0 },
     { 'score': 75 },
     { 'score': 76 },
     { 'score': 76 },
     { 'score': 76 },
     { 'score': 77 },
     { 'score': 77 },
     { 'score': 77 },
     { 'score': 78 },
     { 'score': 79 },
     { 'score': 80 },
     { 'score': 80 },
     { 'score': 10 },
]

# sort photos by score
photos.sort(lambda x,y : cmp(x['score'], y['score']))

def rank(s):
    N = len(s)
    if N == 0:
        return
    p = 1
    topScore = 999999
    # visit s[N-1], s[N-2], ... s[1], s[0]
    for k in range(N-1, -1, -1):
        if s[k]['score'] < topScore:
            p = N - k
            topScore = s[k]['score']
        s[k]['place'] = p
        s[k]['tied'] = False
        if k < N-1 and s[k+1]['place'] == p:
            s[k]['tied'] = True
            s[k+1]['tied'] = True
    
rank(photos);
for p in photos:
    if p['tied']:
        print 'Shared %4s place: %3s' % (p['place'], p['score'])
    else:
        print '       %4s place: %3s' % (p['place'], p['score'])
