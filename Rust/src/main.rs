use std::time::Instant;
use std::hint::black_box;

fn main() {
    let count = 20_000_000;
    
    let mut values: Vec<u64> = Vec::with_capacity(count * 2);

    let time_now = Instant::now();

    for i in 0..count {
        values.push(i as u64);
    }

    for i in (1..=count).rev() {
        values.push(i as u64);
    }

    let time_exec = time_now.elapsed();
    let ms = time_exec.as_nanos() as f64 / 1_000_000.0;

    println!("time exec in milliseconds: {:.3}", ms);
    
    let anti_trapaca = values[0] + values[values.len() - 1];
    black_box(anti_trapaca);
}