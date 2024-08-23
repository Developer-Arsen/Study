import { exec } from 'child_process';
import path from 'path';

export default function arsenstart() {
  console.log("arsena start tvel")

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


