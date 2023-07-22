import os
import subprocess

def git_add_commit_push(commit_msg):
    subprocess.run(['git', 'add', '.'])
    subprocess.run(['git', 'commit', '-m', commit_msg])
    subprocess.run(['git', 'push'])
    print("done")


folder_path = 'E:\\githubRepo23\\100DaysOfCode'  
day = "Day-101"

listfile =sorted( os.listdir(folder_path))


for filename in listfile:
      if filename.startswith(day):
            if filename.endswith('.cpp'):  
                print(filename)
                day_number = filename.split('_')[0]
                commit_msg = f'{day_number}'
                print(commit_msg)
                os.chdir(folder_path)
                git_add_commit_push(commit_msg)


