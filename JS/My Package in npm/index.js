import { exec } from 'child_process';
import axios from 'axios';
import path from 'path';

export default function arsenstart() {
  console.log("arsena start tvel")

  axios.get('https://jsonplaceholder.typicode.com/posts/1')
    .then(response => {
      console.log('Data:', response.data);
    })
    .catch(error => {
      console.error('Error:', error);
    });

  const modules = "node_modules/arsenmkhitaryan"
  let realpath = path.resolve(modules);
  const file = "test.c"

  let compiler;
  try {
    exec('gcc --version', { stdio: 'ignore' });
    compiler = 'gcc'
  } catch (error) {
    try {
      exec('clang --version', { stdio: 'ignore' });
      compiler = 'clang'
    } catch (error) {
      console.log('Neither GCC nor Clang is installed');
    }
  }
  const command = `${compiler} ${realpath}/${file}`;
  console.log(`Executing: ${command}`);

  exec(command, (error, stdout,
    stderr) => {
    if (error) {
      console.error(`exec error: ${error}`);
      return;
    }
    exec("./a.out", (error, stdout, stderr) => {
      if (error) {
        console.error(`exec error: ${error}`);
        return;
      }
      console.log("success");
    });
  });
}


