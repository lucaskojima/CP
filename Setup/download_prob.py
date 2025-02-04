#!/usr/bin/env python3
from http.server import BaseHTTPRequestHandler, HTTPServer
import sys
import json
import subprocess
import os

if len(sys.argv) != 2:
    print(f"Usage: {os.path.basename(__file__)} <problem_name>")
    sys.exit(1)

PORT = 10043

class RequestHandler(BaseHTTPRequestHandler):
    def log_message(self, format, *args):
        return

    def do_POST(self):
        content_length = int(self.headers['Content-Length'])
        post_data = self.rfile.read(content_length)
        try:
            data = json.loads(post_data)
            problem_name = sys.argv[1]

            print(f"Got data {json.dumps(data)}")

            subprocess.run(["./generate_prob.sh", problem_name], check=True)

            for idx, test in enumerate(data.get('tests', [])):
                input_filename = os.path.join(problem_name, f"sample{idx + 1}.in")
                output_filename = os.path.join(problem_name, f"sample{idx + 1}.out")
                with open(input_filename, 'w') as infile:
                    infile.write(test['input'])
                with open(output_filename, 'w') as outfile:
                    outfile.write(test['output'])

            self.send_response(200)
            print(f"Saved {idx + 1} sample(s).")
        except json.JSONDecodeError:
            self.send_response(400)
            self.wfile.write(b'Invalid JSON')
        except subprocess.CalledProcessError:
            self.send_response(500)
            self.wfile.write(b'Error running generate_prob.sh')
        self.end_headers()

        sys.exit(0)

if __name__ == "__main__":
    try:
        server = HTTPServer(('0.0.0.0', PORT), RequestHandler)
        server.handle_request()
    except Exception as e:
        print(f"Error: {e}")
        exit(1)
