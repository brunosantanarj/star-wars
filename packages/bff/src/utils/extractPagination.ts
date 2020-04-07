export default (value: string | null): number | null => value
  ? +value.match(/(\d+)(?!.*\d)/)[0]
  : null;
