import nltk
from nltk.tokenize import TweetTokenizer

class Analyzer():
    """Implements sentiment analysis."""

    def __init__(self, positives, negatives):
        """Initialize Analyzer."""

        # TODO
        self.positives = []
        self.negatives = []
        
        fp = open("positive-words.txt", 'r')
        for i in fp:
            if not i.startswith(';'):
                self.positives += i.strip('\n').split()
        fp.close()
        
        fn = open("negative-words.txt", 'r')
        for i in fn:
            if not i.startswith(';'):
                self.negatives += i.strip('\n').split()        
        fn.close()        

    def analyze(self, text):
        """Analyze text for sentiment, returning its score."""

        # TODO
        tokenizer = TweetTokenizer()
        tokens = tokenizer.tokenize(text)
        score = 0
        
        for i in tokens:
            if(i.lower() in self.positives):
                score += 1
            elif(i.lower() in self.negatives):
                score += -1
            
        return score