import sys
import requests
import re
from bs4 import BeautifulSoup
from getpass import getpass

'''
This code is written by kutimotitokura, keidaroo => https://github.com/kutimoti/AtCoderSubmitter.vim/blob/master/pythonx/AtCoderSubmitter.py 
'''

session = requests.Session()
is_logged_in = False

def LoginSession(payload):
    r = session.get('https://beta.atcoder.jp/login')
    soup = BeautifulSoup(r.text,"html.parser")
    csrf_token = soup.find(attrs = {'name' : 'csrf_token'}).get('value')
    payload['csrf_token'] = csrf_token
    session.post('https://beta.atcoder.jp/login' , data = payload)

def Login(username,password):
    payload = {
        'username' : username,
        'password' : password
    }
    LoginSession(payload)
    is_logged_in = True

def Submit(contest_id,problem_id,source):
    submit_page = session.get('https://beta.atcoder.jp/contests/%s/submit' % contest_id)
    submit_data = {
        'data.TaskScreenName': problem_id,
        'data.LanguageId' : 3003, # This means C++14 (gcc)
        'sourceCode' : source
    }
    soup = BeautifulSoup(submit_page.text,"lxml")
    csrf_token = soup.find(attrs = {'name' : 'csrf_token'}).get('value')
    submit_data['csrf_token'] = csrf_token
    result = session.post('https://beta.atcoder.jp/contests/%s/submit' % contest_id ,data = submit_data)
    return result.status_code == requests.codes.ok

def SubmitCode(contest_id,problem_id):
    if not IsLoggedIn():
        vimecho("AtCoderSubmitter is not logged in.")
        return
    source = '\n'.join(vim.eval('getline(0,"$")'))
    if Submit(contest_id,problem_id,source) == 1:
        vimecho('Submit')

def ShowSubmissions(url,args):
    soup = BeautifulSoup(session.get(url , data = args).text,"html.parser")
    trs = soup.find("tbody").find_all("tr")
    vim.command('new ACSubmission')
    vim.command('setlocal buftype=nowrite ')
    for tr in trs:
        judge = tr.find(attrs = {'class' : re.compile('label label')}).text
        score = tr.find(attrs = {'class' : 'text-right submission-score'}).text
        problem = tr.find("a" , href = re.compile('tasks')).text
        user = tr.find("a" , href = re.compile('users')).text
        vim.current.buffer.append('{0} = [{1} - {2}] @{3}'.format(problem , judge , score , user))


def MySubmissions(contest_id):
    if not IsLoggedIn():
        vimecho("AtCoderSubmitter is not logged in.")
        return
    ShowSubmissions('https://beta.atcoder.jp/contests/%s/submissions/me' % contest_id,{})

def EasySubmit():
    responce = requests.get('http://localhost:8080/')

    if responce.status_code != 200:
        vimecho("Oops! You have to turn on your server first. Take a look at README to solve it")    
    else:
        responceList=responce.text.split(' ')
        SubmitCode(responceList[0],responceList[1])

if __name__ == "__main__":
    username = input("username: ")
    password = getpass("password: ")
    Login(username, password)
